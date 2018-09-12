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
	long long audioLength(const QAudioFormat & format, qint64 microSeconds);
	void PaintTiles(long long lenght, QByteArray buffer);
	void paintEvent(QPaintEvent *)override;
	void PaintTile(int);
	void smth(int index);
 signals:
	void LineDrawn(AudioFrame*);
private slots:
	void readBuffer();
	void audioDecoded();
private:
	void ReadFormat();
	int tilePixelOffset(qint64 positionOffset) const;
	void CalculateTiles();
	bool isFirstTimeRead = true;
	void CreatePixmaps(QSize);
	QScopedPointer<QAudioDecoder> decoder;
	QAudioFormat format;
	long tileLenght;
	QScopedPointer<AudioAnalyser> analyser;
	long windowLenght;
	AudioRecognition recognizer;
	long long windowSize;
	QSize pixmapSize;
	long long bufferLenght;
	QString path;
	long long bufferPosition;
	QByteArray data;
	int singlebufferLenght;
	std::vector<QAudioBuffer> buffers;
	const long long  windowsDuration = 500 * 1000;
	std::vector<QPixmap*> pixmaps;
	Ui::AudioFrame ui;

	// new things
	std::vector<double> audioFrames;
	std::vector<double> audioSamples;
	int bufferbytecount; 
	void nomralize();
	void rms();
};
