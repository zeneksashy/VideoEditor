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
private slots:
	void OnButtonClick();
private:
	void ConnectUi();
	void ChangeButtonColor();
	void TurnOnOffTrack();
	MediaTrack* currentTrack;
	bool isClicked;
	Ui::SingleTrack ui;
	uint audioTracks;
	uint videoTracks;
	static uint videoCounter;
	static uint audioCounter;
};
