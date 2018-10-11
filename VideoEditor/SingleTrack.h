#pragma once
#include <QWidget>
#include "ui_SingleTrack.h"
#include"MediaTrack.h"
#include"AudioTrack.h"
#include"VideoTrack.h"
class SingleTrack : public QWidget
{
	Q_OBJECT
public:
	SingleTrack(QWidget *parent = Q_NULLPTR);
	~SingleTrack();
	void CreateMediaTrack(MediaTrack*);
	void dropEvent(QDropEvent *e);
	void dragEnterEvent(QDragEnterEvent *event);
private slots:
	void OnButtonClick();
public slots:
	void itemMoved();
private:
	void InsertToMediaTrack(MediaTrack*);
	void ConnectUi();
	void ChangeButtonColor();
	void TurnOnOffTrack();
	MediaTrack* currentTrack;
	bool isClicked;
	bool AudioVideo; // true  = video, false = audio ,default is video
	Ui::SingleTrack ui;
	uint audioTracks;
	uint videoTracks;
	static uint videoCounter;
	static uint audioCounter;
};
