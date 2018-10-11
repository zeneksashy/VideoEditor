#include "MediaTrack.h"


MediaTrack::~MediaTrack()
{
}

void MediaTrack::mousePressEvent(QMouseEvent *)
{
	this->drawOutline();
}

void MediaTrack::mouseMoveEvent(QMouseEvent *)
{
	QDrag *drag = new QDrag(this);
	QMimeData *mimeData = new QMimeData;
	long long addr = (long long)this;
	std::cout << "Drag int " << addr << "\n";
	mimeData->setText(QString::number(addr));
	drag->setMimeData(mimeData);
	Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
}
