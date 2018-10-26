#include "MediaTrack.h"

MediaTrack::~MediaTrack()
{
}

void MediaTrack::mousePressEvent(QMouseEvent *e)
{
	if (e->button() == Qt::RightButton)
	{
		//show menu
	}
}

void MediaTrack::enterEvent(QEvent *e)
{
	this->drawOutline();
	setCursor(Qt::PointingHandCursor);
}

void MediaTrack::leaveEvent(QEvent *e)
{
	this->deleteOutline();
	unsetCursor();
}

void MediaTrack::PlayMedia()
{
	player->Play();
}

void MediaTrack::PauseMedia()
{
	player->Pause();
}

void MediaTrack::StopMedia()
{
	player->Stop();
}

void MediaTrack::mouseMoveEvent(QMouseEvent *)
{
	QDrag *drag = new QDrag(this);
	QMimeData *mimeData = new QMimeData;
	long long addr = (long long)this;
	mimeData->setText(QString::number(addr));
	drag->setMimeData(mimeData);
	Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
	emit itemMoved(this);
}

void MediaTrack::setPlayer(QString path,MediaType type)
{
	player = std::make_unique<Player>(new Player());
	player->loadFile(path,type);
}
