#pragma once

#include <QWidget>
#include "ui_TimeLine.h"
#include <QDragEnterEvent>
#include"AudioRecognition.h"
#include"VideoLoader.h"
#include<AudioFrame.h>
#include <QAudioDecoder>
#include"VideoFrame.h"
#include<map>
class TimeLine : public QWidget, public VideoLoader
{
	Q_OBJECT

public:
	void loadFile(QString) override;
	TimeLine(QWidget *parent = Q_NULLPTR);

	
	void dragEnterEvent(QDragEnterEvent* event);
	void dropEvent(QDropEvent* e);


private slots:
	void itemSelected(QListWidgetItem*);
	void LineSelected(MediaFrame*);
private:
	QScopedPointer<QAudioDecoder> decoder;
	QScopedPointer<AudioAnalyser> analyser;
	bool CheckAudio();
	bool CheckVideo();
	AudioRecognition recognizer;
	VideoFrame* CreateVideoFrame(QString);
	std::vector<QAudioBuffer> buffers;
	AudioFrame* CreateAudioFrame(QString);
	void CreateFrame(qint64 size);
	static const  QStringList supportedFormats;
	static const  std::list<std::string> supportedFormats1;
	Ui::TimeLine ui;
	QScopedPointer<QHBoxLayout> layout;
	std::map<QListWidgetItem*, AudioFrame*> audioSources;
	std::map<QListWidgetItem*, VideoFrame*> videoSources;
};
