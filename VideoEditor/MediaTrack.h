#pragma once
#include <QWidget>
#include <ctime>
#include<qlistwidget.h>
#include <QMouseEvent>
#include<qdrag.h>
#include<qmimedata.h>
class MediaTrack: public QWidget
{
	Q_OBJECT
public:
	MediaTrack(QWidget* parent) :QWidget(parent) {}
	virtual ~MediaTrack();
	virtual void drawOutline() = 0;
	virtual void deleteOutline() = 0;
	virtual void ResizeFrame(int) = 0;
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
}; 

