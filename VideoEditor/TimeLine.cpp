#include "TimeLine.h"
#include <QDragEnterEvent>
#include<qmimedata.h>
#include<qmessagebox.h>
#include <algorithm>
#include"MediaManager.h"
#include"qmediaplayer.h"
#include <QAudioFormat>
#include <QAudioDecoder>
#include<complex>
#include<vector>
#include <AudioTrack.h>
#include<SingleTrack.h>
//TODO
// add correct slider range
//add resizinig to line drawing
//change start position of resizing multipler to 10 , 1 to min and 20 to max
//add auto scrolling when line get out of scope -- done


TimeLine::TimeLine(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setAcceptDrops(true);
	layout.reset(new QHBoxLayout);
	connect(MediaManager::player, &Player::positionChanged, this, &TimeLine::updateTime);
	connect(MediaManager::player, &Player::videoStopped, this, &TimeLine::stopTimeLine);
	connect(ui.zoomingSlider, &QSlider::valueChanged, this, &TimeLine::ResizeFrames);
	setMouseTracking(true);
	i = 0;
	scale = 5;
	multipler = scale;
	ui.Content->installEventFilter(this);
	ui.scrollAreaWidgetContents->installEventFilter(this);
}

void TimeLine::ResizeFrames(int p)
{
	scale = p;
	ui.zoomingSlider->blockSignals(true);
	try
	{
		auto  audioIt = audioSources.begin();
		auto  videoIt = videoSources.begin();
		for (; audioIt != audioSources.end(), videoIt != videoSources.end(); audioIt++, videoIt++)
		{
			videoIt->second->ResizeFrame(p);
			audioIt->second->ResizeFrame(p);
		}
		ui.zoomingSlider->blockSignals(false);
	}
	catch (const std::exception& e)
	{
		e.what();
	}
	
}

void TimeLine::stopTimeLine()
{
	i = 0;
	UpdateTimeLabel(i);
	update();
	ui.horizontalSlider->setValue(i);
}

void TimeLine::wheelEvent(QWheelEvent *e)
{
	/*try
	{
		auto p = e->angleDelta();
		p.setY(p.y() / 120);
		e->accept();
		ResizeFrames(p);
	}
	catch (const std::exception& e)
	{
		e.what();
	}*/
}
void TimeLine::UpdateTimeLabel(int pos)
{
	std::stringstream s;
	int sec = pos / MediaManager::player->getFrameRate();
	int min = sec / 60;
	int h = min / 60;
	if (sec >= 60)
		sec %= 60;
	if (min >= 60)
		min %= 60;
	(h>10)?s << h << ":":s<<"0"<<h<<":";
	(min > 10) ? s << min << ":" : s << "0" << min << ":";
	(sec > 10) ? s << sec: s << "0" << sec;
	std::string time = s.str();
	ui.timeLabel->setText(QString::fromStdString(time));
}

void TimeLine::loadFile(QString path)
{
	//auto item = new QListWidgetItem();
	//need to add format checker for item
	framesCount = MediaManager::player->getVideCapture()->get(cv::CAP_PROP_FRAME_COUNT);
//	auto item = new QListWidgetItem(path, ui.sourcesList);
	//connect(ui.sourcesList, &QListWidget::itemClicked, this, &TimeLine::itemSelected);
	ui.horizontalSlider->setRange(0, framesCount);
	ui.horizontalSlider->setFixedWidth(framesCount);
	//QListWidgetItem &dl = *item;
	QBrush brush(QColor::fromRgb(128, 130, 128));
	//item->setBackground(brush);
	if (MediaManager::player->isVideoAvaible())
	{
		videoSources.insert({ nullptr , CreateVideoTrack(path) });
		//auto  x = CreateVideoTrack(path);
	}
	if (MediaManager::player->isAudioAvaible())
	{
		audioSources.insert({ nullptr , CreateAudioTrack(path) });
		//auto x = CreateAudioTrack(path);
	}
	timeLineSizeMultipler = ui.widget->width();
}
void TimeLine::updateTime()
{
	update();
	UpdateTimeLabel(i);
	ui.horizontalSlider->setValue(i);
	if (i == timeLineSizeMultipler-15)
	{
		timeLineSizeMultipler += timeLineSizeMultipler;
		ui.scrollArea->horizontalScrollBar()->setValue(i);
	}
	++i;	
}
void TimeLine::dragEnterEvent(QDragEnterEvent * e)
{
	if (e->mimeData()->hasUrls()) {
		e->acceptProposedAction();
	}
}

bool TimeLine::eventFilter(QObject * watched, QEvent * event)
{//for now is 1 move per frames,  25 frames per second
	if (event->type() == QEvent::Paint)
	{
		//int timelineMultipler = i/(multipler/scale) ;
		watched->event(event);
		auto widget = dynamic_cast<QWidget*>(watched);
		auto media = dynamic_cast<MediaTrack*>(watched);
		QPainter painter(widget);
		painter.setPen(QPen(Qt::red, 1));
		painter.setBrush(Qt::BrushStyle::SolidPattern);
		if(media)
			painter.drawLine(i, 0, i, ui.Content->rect().height());
		else
			painter.drawLine(i+87, 0, i+87, ui.Content->rect().height());
		return true; // The event is already handled.
	}
	return false;
}
void TimeLine::dropEvent(QDropEvent * e)
{
	foreach(const QUrl &url, e->mimeData()->urls()) {
		MediaManager::LoadMedia(url.toLocalFile());
	}
}
void TimeLine::itemSelected(QListWidgetItem* item)
{
	for each (auto source in audioSources)
	{
		source.second->deleteOutline();
	}
	for each (auto source in videoSources)
	{
		source.second->deleteOutline();
	}
	audioSources.find(item)->second->drawOutline();
	videoSources.find(item)->second->drawOutline();
}

void TimeLine::LineSelected(MediaTrack * frame)
{
	auto  audioIt = audioSources.begin();
	auto  videoIt = videoSources.begin();
	for (;audioIt!=audioSources.end(),videoIt!=videoSources.end();audioIt++,videoIt++)
	{
		if (audioIt->second == frame)
		{
			audioIt->first->setSelected(true);
			audioIt->second->drawOutline();

			if (videoIt->first == audioIt->first)
			{
				videoIt->first->setSelected(true);
				videoIt->second->drawOutline();
			}
			continue;
		}
		if (videoIt->second == frame)
		{
			videoIt->first->setSelected(true);
			videoIt->second->drawOutline();

			if (audioIt->first == audioIt->first)
			{
				audioIt->first->setSelected(true);
				audioIt->second->drawOutline();
			}
			continue;
		}
		audioIt->second->deleteOutline();
		videoIt->second->deleteOutline();
	}
}

VideoTrack* TimeLine::CreateVideoTrack(QString path)
{
	auto videoframe = new VideoTrack(this);
	auto singleTrack = new SingleTrack(this);
	singleTrack->CreateMediaTrack(videoframe);
	//connect(videoframe, &VideoTrack::LineSelected, this, &TimeLine::LineSelected);
	videoframe->Initliaize(path);
	//videoframe->show();
	ui.timeline->addWidget(singleTrack);
	videoframe->installEventFilter(this);
	return videoframe;
}
AudioTrack* TimeLine::CreateAudioTrack(QString path)
{
	auto singleTrack = new SingleTrack(this);
	auto audioframe = new AudioTrack(this);
	singleTrack->CreateMediaTrack(audioframe);
	//connect(audioframe, &AudioTrack::LineSelected, this, &TimeLine::LineSelected);
	audioframe->Initialize(path);
	audioframe->show();
	ui.timeline->addWidget(singleTrack);
	audioframe->installEventFilter(this);
	return audioframe;
}


