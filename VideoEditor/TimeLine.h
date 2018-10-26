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
#include"Tester.h"
class TimeLine : public QWidget, public VideoLoader
{
	Q_OBJECT
	friend class TimeLineTest;
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
	VideoTrack* CreateVideoTrack(QString);
	AudioTrack* CreateAudioTrack(QString);
	void ConfigureButtons();
	void ConnectUi();
	Ui::TimeLine ui;
	QScopedPointer<QHBoxLayout> layout;
	std::map<QListWidgetItem*, AudioTrack*> audioSources;
	std::map<QListWidgetItem*, VideoTrack*> videoSources;
};
class TimeLineTest
{
public:
	TimeLineTest()
	{
		MediaManager::LoadWidget(&timeLine);
		MediaManager::LoadMedia(QString::fromStdString(mediaPath));
		
	}
	~TimeLineTest()
	{
		MediaManager::ClearAllWidgets();
		MediaManager::indexer->ClearAllTracks();
	}
	bool NewTrackTest()
	{
		if (timeLine.audioSources.size() !=1 || timeLine.videoSources.size() != 1)
			return false;
		return true;
	}
	bool timeLabelSecondsParse()
	{
		timeLine.UpdateTimeLabel(1500);
		auto str = timeLine.ui.timeLabel->text();
		if (str == "00:01:00")
			return true;
		return false;
	}
private:
	const std::string mediaPath = "C:\\Users\\gzeniuk\\Downloads\\SampleVideo_720x480_30mb.mp4";
	//	std::unique_ptr<TimeLine> timeLine;
	TimeLine timeLine;
};
