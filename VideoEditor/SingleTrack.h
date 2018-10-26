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
	void dragLeaveEvent(QDragLeaveEvent *event);
	void PlayTrack();
	void PauseTrack();
	void StopTrack();
	bool isTtrackAvaible() { return isAvaible; }
	bool isVideoTrack() { return AudioVideo; }
	MediaTrack* currentTrack;
signals:
	void ImageProcessed(const QImage&);
	void MediaAvailability(bool,SingleTrack*);
private slots:
	void OnImageProcessed(const QImage&);
	void OnButtonClick();
public slots:
	void itemRemoved(MediaTrack*);
	void NextTrack();
private:
	void InsertToMediaTrack(MediaTrack*);
	void ConnectUi();
	void ChangeButtonColor();
	void TurnOnOffTrack();
	bool isFirst;
	void AssignCurrentToFirst();
	int currentTrackId;
	bool isAvaible;
	bool isClicked;
	bool AudioVideo; // true  = video, false = audio ,default is video
	Ui::SingleTrack ui;
	uint audioTracks;
	uint videoTracks;
	static uint videoCounter;
	static uint audioCounter;
	uint opacity;
};
