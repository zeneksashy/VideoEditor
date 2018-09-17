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
	QMediaPlayer mediaplayer;
	mediaplayer.setMedia(QUrl::fromLocalFile(path));
	auto item = new QListWidgetItem(path, ui.sourcesList);
	connect(ui.sourcesList, &QListWidget::itemClicked, this, &TimeLine::itemSelected);
	QListWidgetItem &dl = *item;
	QBrush brush(QColor::fromRgb(128, 130, 128));
	item->setBackground(brush);
	
	if (MediaManager::player.isVideoAvaible())
	{
		// TODO
		
	}
	if (MediaManager::player.isAudioAvaible())
	{
		sources.insert({ item , CreateAudioFrame(path) });
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
	for each (auto source in sources)
	{
		source.second->deleteOutline();
	}
	sources.find(item)->second->drawOutline();
	
}
void TimeLine::audioFrameDrawn(AudioFrame* frame)
{
	ui.timeline->addWidget(frame);
}
void TimeLine::LineSelected(AudioFrame * frame)
{
	for each (auto source in sources)
	{
		if (source.second == frame)

		{
			source.first->setSelected(true);
			continue;
		}
		source.second->deleteOutline();
			
	}
}
const QStringList TimeLine::supportedFormats = QStringList{ "audio/x-au","audio/aiff","application/octet-stream", "video/x-msvideo", "video/mp4", "audio/mpeg", "audio/mp4" ,"video/x-ms-wmv","video/avi" ,"video/mpeg","audio/x-mpeg-3","audio/mpeg3"};
const std::list<std::string> TimeLine::supportedFormats1 = std::list<std::string>{ "audio/x-au","audio/aiff","application/octet-stream", "video/x-msvideo", "video/mp4", "audio/mpeg", "audio/mp4" ,"video/x-ms-wmv","video/avi" ,"video/mpeg","audio/x-mpeg-3","audio/mpeg3" };
void TimeLine::CreateVideoFrame(QString path)
{
	VideoFrame* videoframe = new VideoFrame(this);
	videoframe->Initliaize(path);
	videoframe->show();
	ui.timeline->addWidget(videoframe);
}
AudioFrame* TimeLine::CreateAudioFrame(QString path)
{
	auto audioframe = new AudioFrame(this);
	connect(audioframe, &AudioFrame::LineSelected, this, &TimeLine::LineSelected);
	connect(audioframe, &AudioFrame::LineDrawn, this, &TimeLine::audioFrameDrawn);
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


