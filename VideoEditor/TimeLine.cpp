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
#include <AudioFrame.h>

//TODO
// add correct slider range
//add resizinig to line drawing
//change start position of resizing multipler to 10 , 1 to min and 20 to max
//add auto scrolling when line get out of scope
//add mutliplying i by resizer multipler
//add label on top of timeline with time

TimeLine::TimeLine(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setAcceptDrops(true);
	layout.reset(new QHBoxLayout);
	auto scroll = ui.scrollArea_2->horizontalScrollBar();
	auto scroll1 = ui.scrollArea->horizontalScrollBar();
	connect(scroll, &QScrollBar::sliderMoved, scroll1, &QScrollBar::setValue);
	connect(MediaManager::player, &Player::positionChanged, this, &TimeLine::updateTime);
	connect(ui.zoomingSlider, &QSlider::valueChanged, this, &TimeLine::ResizeFrames);
	ui.horizontalSlider->setRange(0, 4800);
	ui.horizontalSlider->setFixedWidth(4800);
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
	auto item = new QListWidgetItem(path, ui.sourcesList);
	connect(ui.sourcesList, &QListWidget::itemClicked, this, &TimeLine::itemSelected);
	QListWidgetItem &dl = *item;
	QBrush brush(QColor::fromRgb(128, 130, 128));
	item->setBackground(brush);
	if (MediaManager::player->isVideoAvaible())
	{
		videoSources.insert({ item , CreateVideoFrame(path) });
	}
	if (MediaManager::player->isAudioAvaible())
	{
		audioSources.insert({ item , CreateAudioFrame(path) });
	}
}
void TimeLine::updateTime()
{
	update();
	UpdateTimeLabel(i);

	
	ui.horizontalSlider->setValue(i);
	++i;
	//multipler =  MediaManager::player->getFrameRate();
}
void TimeLine::dragEnterEvent(QDragEnterEvent * e)
{
	if (e->mimeData()->hasUrls()) {
		e->acceptProposedAction();
	}
}

bool TimeLine::eventFilter(QObject * watched, QEvent * event)
{//for now is 1 move per frames, == 25 frames per second
	if (event->type() == QEvent::Paint)
	{
		//int timelineMultipler = i/(multipler/scale) ;
		watched->event(event);
		auto widget = dynamic_cast<QWidget*>(watched);
		QPainter painter(widget);
		painter.setPen(QPen(Qt::red, 1));
		painter.setBrush(Qt::BrushStyle::SolidPattern);
		painter.drawLine(i, 0, i, ui.Content->rect().height());
	//	painter.drawLine(i, 0, i, rect().height());
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

void TimeLine::LineSelected(MediaFrame * frame)
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
const QStringList TimeLine::supportedFormats = QStringList{ "audio/x-au","audio/aiff","application/octet-stream", "video/x-msvideo", "video/mp4", "audio/mpeg", "audio/mp4" ,"video/x-ms-wmv","video/avi" ,"video/mpeg","audio/x-mpeg-3","audio/mpeg3"};
const std::list<std::string> TimeLine::supportedFormats1 = std::list<std::string>{ "audio/x-au","audio/aiff","application/octet-stream", "video/x-msvideo", "video/mp4", "audio/mpeg", "audio/mp4" ,"video/x-ms-wmv","video/avi" ,"video/mpeg","audio/x-mpeg-3","audio/mpeg3" };
VideoFrame* TimeLine::CreateVideoFrame(QString path)
{
	auto videoframe = new VideoFrame(this);
	connect(videoframe, &VideoFrame::LineSelected, this, &TimeLine::LineSelected);
	videoframe->Initliaize(path);
	videoframe->show();
	ui.timeline->addWidget(videoframe);
	videoframe->installEventFilter(this);
	return videoframe;
}
AudioFrame* TimeLine::CreateAudioFrame(QString path)
{
	auto audioframe = new AudioFrame(this);
	connect(audioframe, &AudioFrame::LineSelected, this, &TimeLine::LineSelected);
	audioframe->Initialize(path);
	audioframe->show();
	ui.timeline->addWidget(audioframe);
	audioframe->installEventFilter(this);
	return audioframe;
}


