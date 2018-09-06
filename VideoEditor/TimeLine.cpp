#include "TimeLine.h"
#include <QDragEnterEvent>
#include<qmimedata.h>
#include<qmessagebox.h>
#include <algorithm>
#include"MediaManager.h"
#include"qmediaplayer.h"
#include <QAudioFormat>
#include <QAudioDecoder>
TimeLine::TimeLine(QWidget *parent)
	: QWidget(parent)
{
	setAcceptDrops(true);
	ui.setupUi(this);
	layout.reset(new QHBoxLayout);
}

void TimeLine::loadFile(QString path)
{
	QMediaPlayer mediaplayer;
	mediaplayer.setMedia(QUrl::fromLocalFile(path));
	auto size = mediaplayer.duration();
	if (MediaManager::player.isVideoAvaible())
	{
		//createvideoframe
	}
	if (MediaManager::player.isAudioAvaible())
	{
		decoder.reset(new QAudioDecoder());
		//auto decoder = new QAudioDecoder;
		decoder->setSourceFilename(path);
		connect(decoder.data(), SIGNAL(bufferReady()), this, SLOT(readBuffer()));
		decoder->start();
		//createaudioframe
	}
	CreateFrame(size);
}
TimeLine::~TimeLine()
{
}
//this should be in separate class
void TimeLine::readBuffer()
{
	auto data = decoder->read();
	int x = data.sampleCount();
	auto arr = QByteArray::fromRawData(data.constData<char>(), 9600);
	auto format = data.format();
	auto size = format.sampleSize();//16
	auto count = format.channelCount();//2
	auto sample = format.sampleType();//signed int
	recognzer.RrecognizeFrameType(data,format);
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
		QMessageBox msgBox;
		msgBox.setText("file dropped");
		msgBox.exec();
	}
}
const QStringList TimeLine::supportedFormats = QStringList{ "audio/x-au","audio/aiff","application/octet-stream", "video/x-msvideo", "video/mp4", "audio/mpeg", "audio/mp4" ,"video/x-ms-wmv","video/avi" ,"video/mpeg","audio/x-mpeg-3","audio/mpeg3"};
const std::list<std::string> TimeLine::supportedFormats1 = std::list<std::string>{ "audio/x-au","audio/aiff","application/octet-stream", "video/x-msvideo", "video/mp4", "audio/mpeg", "audio/mp4" ,"video/x-ms-wmv","video/avi" ,"video/mpeg","audio/x-mpeg-3","audio/mpeg3" };
void TimeLine::CreateFrame(qint64 size)
{

	QWidget *frame = new QWidget(ui.Content);
	frame->setObjectName("2");
	frame->setSizePolicy(
		QSizePolicy::Preferred, QSizePolicy::Preferred);
	QPalette pal = palette();
	frame->setStyleSheet("background-color:red;");
	frame->setVisible(true);

	ui.timeline->addWidget(frame);
	ui.Content->show();
}
bool TimeLine::CheckMimeTypes(QMimeData& data)
{
	//td::all_of(supportedFormats1.begin(),supportedFormats1.end(),)
	return true;
}

