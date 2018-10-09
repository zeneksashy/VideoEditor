#pragma once

#include <QWidget>
#include "ui_TimeLine.h"
#include <QDragEnterEvent>
#include"AudioRecognition.h"
#include"VideoLoader.h"
#include<AudioFrame.h>
#include <QAudioDecoder>
#include"VideoFrame.h"
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
	void LineSelected(MediaFrame*);
	void ResizeFrames(int);
	void stopTimeLine();
private:
	uint i;
	uint scale;
	float multipler;
	void wheelEvent(QWheelEvent *e)override;
	void UpdateTimeLabel(int);
	QScopedPointer<QAudioDecoder> decoder;
	QScopedPointer<AudioAnalyser> analyser;
	bool CheckAudio();
	bool CheckVideo();
	AudioRecognition recognizer;
	VideoFrame* CreateVideoFrame(QString);
	std::vector<QAudioBuffer> buffers;
	AudioFrame* CreateAudioFrame(QString);
	static const  QStringList supportedFormats;
	static const  std::list<std::string> supportedFormats1;
	Ui::TimeLine ui;
	QScopedPointer<QHBoxLayout> layout;
	std::map<QListWidgetItem*, AudioFrame*> audioSources;
	std::map<QListWidgetItem*, VideoFrame*> videoSources;
};
