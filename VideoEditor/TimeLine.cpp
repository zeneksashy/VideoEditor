#include "TimeLine.h"
#include <QDragEnterEvent>
#include<qmimedata.h>
#include<qmessagebox.h>
#include <algorithm>
#include"MediaManager.h"
#include"qmediaplayer.h"
TimeLine::TimeLine(QWidget *parent)
	: QWidget(parent)
{
	setAcceptDrops(true);
	ui.setupUi(this);
	layout.reset(new QHBoxLayout);
}

void TimeLine::loadVideo(QString path)
{
	auto mediaplayer = new QMediaPlayer;
	mediaplayer->setMedia(QUrl::fromLocalFile(path));
	auto size = mediaplayer->duration();
	CreateFrame(size);
}
TimeLine::~TimeLine()
{
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
		//QString fileName = url.toLocalFile();

		QMessageBox msgBox;
		msgBox.setText("file dropped");
		msgBox.exec();
	}
}
const QStringList TimeLine::supportedFormats = QStringList{ "audio/x-au","audio/aiff","application/octet-stream", "video/x-msvideo", "video/mp4", "audio/mpeg", "audio/mp4" ,"video/x-ms-wmv","video/avi" ,"video/mpeg","audio/x-mpeg-3","audio/mpeg3"};
const std::list<std::string> TimeLine::supportedFormats1 = std::list<std::string>{ "audio/x-au","audio/aiff","application/octet-stream", "video/x-msvideo", "video/mp4", "audio/mpeg", "audio/mp4" ,"video/x-ms-wmv","video/avi" ,"video/mpeg","audio/x-mpeg-3","audio/mpeg3" };
void TimeLine::CreateFrame(qint64 size)
{
	QWidget *frame = new QWidget;
	frame->setSizePolicy(
		QSizePolicy::Preferred, QSizePolicy::Preferred);
	QPalette pal = palette();
	frame->setVisible(true);
	// set black background
	pal.setColor(QPalette::Background, Qt::red);
	frame->setAutoFillBackground(true);
	frame->setPalette(pal);
	ui.timeline->addWidget(frame);
}
bool TimeLine::CheckMimeTypes(QMimeData& data)
{
	//td::all_of(supportedFormats1.begin(),supportedFormats1.end(),)
	return true;
}

