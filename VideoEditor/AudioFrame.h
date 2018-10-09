#pragma once

#include <QWidget>
#include "ui_AudioFrame.h"
#include<qaudiodecoder.h>
#include<qaudioformat.h>
#include<qpixmap.h>
#include<AudioAnalyser.h>
#include<AudioRecognition.h>
#include <ctime>
#include<qlistwidget.h>
#include"MediaFrame.h"
#include <qmouseeventtransition.h>
#include <QMouseEvent>
class AudioRecognition;
class AudioFrame : public QWidget,public MediaFrame
{
	Q_OBJECT

public:
	AudioFrame(QWidget *parent);
	AudioFrame();
	~AudioFrame();
	void Initialize(QString);
	void Initialize(AudioAnalyser*,const QAudioFormat &format, qint64 audioBufferSize);
	void paintEvent(QPaintEvent *)override;
	void drawOutline() override;
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *) override;
	void deleteOutline() override;
	void ResizeFrame(int) override;
signals:
	void LineSelected(AudioFrame*);
private slots:
	void ChangeFormat(const QAudioFormat&);
	void readBuffer();
	void audioDecoded();
private:
	QPoint offset;
	std::vector<double> audioFrames;
	std::vector<double> audioSamples;
	QScopedPointer<QAudioDecoder> decoder;
	QAudioFormat format;
	QScopedPointer<AudioAnalyser> analyser;
	AudioRecognition recognizer;
	QString path;
	FastFourierTransform fft;
	Ui::AudioFrame ui;
	uint templenght;
	uint lenght;
	uint sampleSize;
	uint sampleLenght;
	std::clock_t clk;
	bool isSelected;

};
