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

TimeLine::TimeLine(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setAcceptDrops(true);
	layout.reset(new QHBoxLayout);
	auto mediaplayer = MediaManager::player->getMediaPlayer();
	connect(mediaplayer, &QMediaPlayer::positionChanged, this, &TimeLine::updateTime);
	ui.horizontalSlider->setRange(0, 181311);
	i = 0;
	ui.Content->installEventFilter(this);
}

void TimeLine::ResizeFrames(QPoint p)
{
	try
	{
		auto  audioIt = audioSources.begin();
		auto  videoIt = videoSources.begin();
		for (; audioIt != audioSources.end(), videoIt != videoSources.end(); audioIt++, videoIt++)
		{
			videoIt->second->ResizeFrame(p);
			audioIt->second->ResizeFrame(p);
		}
	}
	catch (const std::exception& e)
	{
		e.what();
	}
	
}
void TimeLine::wheelEvent(QWheelEvent *e)
{
	try
	{
		auto p = e->angleDelta();
		p.setY(p.y() / 120);
		e->accept();
		ResizeFrames(p);
	}
	catch (const std::exception& e)
	{
		e.what();
	}
}
void TimeLine::UpdateTimeLabel(qint64 pos)
{
	std::stringstream s;
	int sec = pos / 1000;
	int min = sec / 60;
	int h = min / 60;
	if (sec >= 60)
		sec %= 60;
	if (min >= 60)
		min %= 60;
	s << h << ":" << min << ":" << sec;
	std::string time = s.str();
	ui.timeLabel->setText(QString::fromStdString(time));
}
void TimeLine::UpdateTimeLine(qint64 pos)
{
	QPixmap pixmap(ui.Content->rect().size());
	pixmap.fill(QColor("transparent"));
	QPainter painter(&pixmap);
	painter.setPen(Qt::red);
	QLine line(pos, 0, pos, rect().height());
	painter.drawLine(line);
//	ui.label->setPixmap(pixmap);

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
void TimeLine::updateTime(qint64 pos)
{
	UpdateTimeLabel(pos);
	UpdateTimeLine(pos/1000);
	ui.horizontalSlider->setValue(pos);
	++i;
	update();
	
}
void TimeLine::dragEnterEvent(QDragEnterEvent * e)
{
	if (e->mimeData()->hasUrls()) {
		e->acceptProposedAction();
	}
}
void TimeLine::paintEvent(QPaintEvent *)
{
	QPainter p(ui.Content);
	p.setPen(Qt::red);
	//auto size = ui.Content->rect().size();
	//auto startpoint = ui.Content->mapToGlobal(ui.Content->rect().topLeft());
	QLine line(285, 0, 285, rect().height());
	p.drawLine(line);
}
bool TimeLine::eventFilter(QObject * watched, QEvent * event)
{
	if (event->type() == QEvent::Paint)
	{
		watched->event(event);
		auto widget = dynamic_cast<QWidget*>(watched);
		QPainter painter(widget);
		painter.setPen(QPen(Qt::red, 1));
		painter.setBrush(Qt::BrushStyle::SolidPattern);
		if(widget==ui.Content)
			painter.drawLine(i+5, 0, i + 5, rect().height());
		else
			painter.drawLine(i, 0, i, rect().height());
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


