#pragma once

#include <QWidget>
#include "ui_AudioFrame.h"
#include<qaudioformat.h>
#include<qpixmap.h>
#include<AudioAnalyser.h>
class AudioFrame : public QWidget
{
	Q_OBJECT

public:
	AudioFrame(QWidget *parent = Q_NULLPTR);
	~AudioFrame();
	void Initialize(AudioAnalyser*,const QAudioFormat &format, qint64 audioBufferSize);
	long long audioLength(const QAudioFormat & format, qint64 microSeconds);
	void PaintTiles(long long lenght, QByteArray buffer);
	void PaintTile(int);
private:
	int tilePixelOffset(qint64 positionOffset) const;
	void CalculateTiles();
	void CreatePixmaps(QSize);
	QAudioFormat format;
	long tileLenght;
	long windowLenght;
	long long windowSize;
	QSize pixmapSize;
	long long bufferLenght;
	long long bufferPosition;
	QByteArray buffer;
	QScopedPointer<AudioAnalyser> analyser;
	const long long  windowsDuration = 500 * 1000;
	std::vector<QPixmap*> pixmaps;
	Ui::AudioFrame ui;
};
