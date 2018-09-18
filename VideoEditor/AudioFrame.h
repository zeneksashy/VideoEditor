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
	void deleteOutline() override;
	void ResizeFrame(int) override;
signals:
	void LineSelected(AudioFrame*);
private slots:
	void ChangeFormat(const QAudioFormat&);
	void readBuffer();
	void audioDecoded();
private:
	int scale;
	int templenght;
	int lenght;
	bool isSelected;
	bool isFirstTimeRead = true;
	QScopedPointer<QAudioDecoder> decoder;
	QAudioFormat format;
	QScopedPointer<AudioAnalyser> analyser;
	AudioRecognition recognizer;
	QString path;
	Ui::AudioFrame ui;
	// new things
	std::vector<double> audioFrames;
	std::vector<double> audioSamples;
	int sampleSize;
	int sampleLenght;
	FastFourierTransform fft;
	std::clock_t clk;

};
