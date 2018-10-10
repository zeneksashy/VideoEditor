#pragma once

#include <QWidget>
#include<qaudiodecoder.h>
#include<qaudioformat.h>
#include<qpixmap.h>
#include<AudioAnalyser.h>
#include<AudioRecognition.h>
#include <ctime>
#include<qlistwidget.h>
#include"MediaTrack.h"
#include <qmouseeventtransition.h>
#include <QMouseEvent>
class AudioRecognition;
class AudioTrack : public MediaTrack
{
Q_OBJECT

public:
	AudioTrack(QWidget *parent);
	AudioTrack();
	~AudioTrack();
	void Initialize(QString);
	void Initialize(AudioAnalyser*,const QAudioFormat &format, qint64 audioBufferSize);
	void paintEvent(QPaintEvent *)override;
	void drawOutline() override;
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *) override;
	void deleteOutline() override;
	void ResizeFrame(int) override;
signals:
	void LineSelected(AudioTrack*);
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
	uint templenght;
	uint lenght;
	uint sampleSize;
	uint sampleLenght;
	std::clock_t clk;
	bool isSelected;

};
