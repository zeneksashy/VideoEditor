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
	item->setBackground(Qt::yellow);
	
	if (MediaManager::player.isVideoAvaible())
	{
		
	}
	if (MediaManager::player.isAudioAvaible())
	{
		//frame = &CreateAudioFrame();
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
	/*	QMessageBox msgBox;
		msgBox.setText("file dropped");
		msgBox.exec();*/
	}
}void TimeLine::itemSelected(QListWidgetItem* item)
{
	auto x = sources.find(item);
	auto y = x->second;
	auto z = x->first;
	sources.find(item)->second->drawOutline();
//	if (item == ui.sourcesList->item()
}
void TimeLine::audioFrameDrawn(AudioFrame* frame)
{
	ui.timeline->addWidget(frame);
}
const QStringList TimeLine::supportedFormats = QStringList{ "audio/x-au","audio/aiff","application/octet-stream", "video/x-msvideo", "video/mp4", "audio/mpeg", "audio/mp4" ,"video/x-ms-wmv","video/avi" ,"video/mpeg","audio/x-mpeg-3","audio/mpeg3"};
const std::list<std::string> TimeLine::supportedFormats1 = std::list<std::string>{ "audio/x-au","audio/aiff","application/octet-stream", "video/x-msvideo", "video/mp4", "audio/mpeg", "audio/mp4" ,"video/x-ms-wmv","video/avi" ,"video/mpeg","audio/x-mpeg-3","audio/mpeg3" };
AudioFrame* TimeLine::CreateAudioFrame(QString path)
{
	auto audioframe = new AudioFrame(this);
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
bool TimeLine::CheckMimeTypes(QMimeData& data)
{
	//td::all_of(supportedFormats1.begin(),supportedFormats1.end(),)
	return true;
}

