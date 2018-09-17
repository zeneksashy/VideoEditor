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
}

void TimeLine::loadFile(QString path)
{

	auto item = new QListWidgetItem(path, ui.sourcesList);
	connect(ui.sourcesList, &QListWidget::itemClicked, this, &TimeLine::itemSelected);
	QListWidgetItem &dl = *item;
	QBrush brush(QColor::fromRgb(128, 130, 128));
	item->setBackground(brush);
	
	if (MediaManager::player.isVideoAvaible())
	{
		// TODO
		videoSources.insert({ item , CreateVideoFrame(path) });
	}
	if (MediaManager::player.isAudioAvaible())
	{
		audioSources.insert({ item , CreateAudioFrame(path) });
	}

}

void TimeLine::dragEnterEvent(QDragEnterEvent * e)
{
	if (e->mimeData()->hasUrls()) {
		e->acceptProposedAction();
	}
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
	//for each (auto source in audioSources)
	//{
	//	if (source.second == frame)
	//	{
	//		source.first->setSelected(true);
	//		source.second->drawOutline();
	//		videoSources.find(source.first)->second->drawOutline();
	//		continue;
	//	}
	//	source.second->deleteOutline();
	//}
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
	return videoframe;
}
AudioFrame* TimeLine::CreateAudioFrame(QString path)
{
	auto audioframe = new AudioFrame(this);
	connect(audioframe, &AudioFrame::LineSelected, this, &TimeLine::LineSelected);
	audioframe->Initialize(path);
	audioframe->show();
	ui.timeline->addWidget(audioframe);
	return audioframe;
}
void TimeLine::CreateFrame(qint64 size)
{
	QWidget *frame = new QWidget(ui.Content);
	frame->setObjectName("2");
	frame->setSizePolicy(
		QSizePolicy::Preferred, QSizePolicy::Preferred);
	QPalette pal = palette();
	frame->setVisible(true);
	frame->setLayout(ui.timeline);
	ui.timeline->addWidget(frame);
	ui.Content->show();
	
}


