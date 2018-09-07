#pragma once

#include <QWidget>
#include "ui_TimeLine.h"
#include <QDragEnterEvent>
#include"AudioRecognition.h"
#include"VideoLoader.h"
#include <QAudioDecoder>
class TimeLine : public QWidget, public VideoLoader
{
	Q_OBJECT

public:
	void loadFile(QString) override;
	TimeLine(QWidget *parent = Q_NULLPTR);
	~TimeLine();
	
	void dragEnterEvent(QDragEnterEvent* event);
	void dropEvent(QDropEvent* e);

private slots:
	void readBuffer();
private:
	QScopedPointer<QAudioDecoder> decoder;
	QScopedPointer<AudioAnalyser> analyser;
	AudioRecognition recognizer;
	void CreateVideoFrame(qint64);
	void CreateAudioFrame(qint64);
	void CreateFrame(qint64 size);
	bool CheckMimeTypes(QMimeData& data);
	static const  QStringList supportedFormats;
	static const  std::list<std::string> supportedFormats1;
	Ui::TimeLine ui;
	QScopedPointer<QHBoxLayout> layout;
};
