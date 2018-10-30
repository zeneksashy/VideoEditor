#pragma once
#include <QWidget>
#include <ctime>
#include<qlistwidget.h>
#include <QMouseEvent>
#include<qdrag.h>
#include<qmimedata.h>
#include<Player.h>
class MediaTrack: public QWidget
{
	Q_OBJECT
public:
	MediaTrack(QWidget* parent) :QWidget(parent),painterPosition(0) {}
	virtual ~MediaTrack();
	virtual void drawOutline() = 0;
	virtual void deleteOutline() = 0;
	virtual void ResizeFrame(int) = 0;
	virtual void Concatenate(MediaTrack*) {}//to inplement
	void mousePressEvent(QMouseEvent *);
	void enterEvent(QEvent*);
	void leaveEvent(QEvent*);
	void PlayMedia();
	void PauseMedia();
	void StopMedia();
	std::unique_ptr<Player>player;
	void mouseMoveEvent(QMouseEvent *);
private slots:
	void PlayerChangedPosition();
signals:
	void PostioonChanged();
	void itemMoved(MediaTrack*);
protected:
	void setPlayer(QString,MediaType);
private:
	uint painterPosition;
}; 

