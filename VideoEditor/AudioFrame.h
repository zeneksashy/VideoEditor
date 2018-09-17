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
class AudioRecognition;
class AudioFrame : public QWidget
{
	Q_OBJECT

public:
	AudioFrame(QWidget *parent);
	AudioFrame();
	~AudioFrame();
	void Initialize(QString);
	void Initialize(AudioAnalyser*,const QAudioFormat &format, qint64 audioBufferSize);
	void paintEvent(QPaintEvent *)override;
	void drawOutline();
	void mousePressEvent(QMouseEvent *);
	void deleteOutline();
signals:
	void LineSelected(AudioFrame*);
	void LineDrawn(AudioFrame*);
public slots:
	//void itemSelected(QListWidgetItem*);
private slots:

	void readBuffer();
	void audioDecoded();
private:
	//static int counter;
	//int id;
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
	int bufferbytecount; 
	int sampleLenght;
	FastFourierTransform fft;
	std::clock_t clk;

};
