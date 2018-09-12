#pragma once

#include <QWidget>
#include "ui_AudioFrame.h"
#include<qaudiodecoder.h>
#include<qaudioformat.h>
#include<qpixmap.h>
#include<AudioAnalyser.h>
#include<AudioRecognition.h>
class AudioRecognition;
class AudioFrame : public QWidget
{
	Q_OBJECT

public:
	AudioFrame(QWidget *parent);
	~AudioFrame();
	void Initialize(QString);
	void Initialize(AudioAnalyser*,const QAudioFormat &format, qint64 audioBufferSize);
	void paintEvent(QPaintEvent *)override;
 signals:
	void LineDrawn(AudioFrame*);
private slots:
	void readBuffer();
	void audioDecoded();
private:
	bool isFirstTimeRead = true;
	QScopedPointer<QAudioDecoder> decoder;
	QAudioFormat format;
	long sampleLenght;
	QScopedPointer<AudioAnalyser> analyser;
	AudioRecognition recognizer;
	QString path;
	Ui::AudioFrame ui;
	// new things
	std::vector<double> audioFrames;
	std::vector<double> audioSamples;
	int bufferbytecount; 
	void nomralize();
	void rms();
};
