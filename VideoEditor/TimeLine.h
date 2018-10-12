#pragma once

#include <QWidget>
#include "ui_TimeLine.h"
#include <QDragEnterEvent>
#include"AudioRecognition.h"
#include"VideoLoader.h"
#include<AudioTrack.h>
#include <QAudioDecoder>
#include"VideoTrack.h"
#include<qpainter.h>
#include<map>
#include <QtGui>
#include <QtWidgets>
class TimeLine : public QWidget, public VideoLoader
{
	Q_OBJECT

public:
	void loadFile(QString) override;
	TimeLine(QWidget *parent = Q_NULLPTR);
	void dragEnterEvent(QDragEnterEvent* event);
	void dropEvent(QDropEvent* e);
	bool eventFilter(QObject* watched, QEvent* event);

private slots:
	void updateTime();
	void itemSelected(QListWidgetItem*);
	void LineSelected(MediaTrack*);
	void ResizeFrames(int);
	void stopTimeLine();
private:
	uint i;
	uint scale;
	uint framesCount;
	int timeLineSizeMultipler;
	void UpdateTimeLabel(int);
	QScopedPointer<AudioAnalyser> analyser;
	AudioRecognition recognizer;
	VideoTrack* CreateVideoTrack(QString);
	AudioTrack* CreateAudioTrack(QString);
	Ui::TimeLine ui;
	QScopedPointer<QHBoxLayout> layout;
	std::map<QListWidgetItem*, AudioTrack*> audioSources;
	std::map<QListWidgetItem*, VideoTrack*> videoSources;
};
