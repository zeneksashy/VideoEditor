#include "AudioFrame.h"
#include <qpaintdevice.h>
#include<qpainter.h>
#include<qbytearray.h>

AudioFrame::AudioFrame(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

AudioFrame::~AudioFrame()
{
}

void AudioFrame::Initialize(AudioAnalyser *analyser, const QAudioFormat & format, qint64 audioBufferSize)
{
	this -> format = format;
	tileLenght = audioBufferSize;
	this->analyser.reset(analyser);
	windowSize = audioLength(format, windowsDuration);

}
long long AudioFrame::audioLength(const QAudioFormat &format, qint64 microSeconds)
{
	qint64 result = (format.sampleRate() * format.channelCount() * (format.sampleSize() / 8))
		* microSeconds / 1000000;
	result -= result % (format.channelCount() * format.sampleSize());
	return result;
}

void AudioFrame::PaintTiles(long long lenght, QByteArray buffer)
{
	bufferLenght = lenght;
	this->buffer = buffer;
	for (size_t i = 0; i < pixmaps.size(); i++)
	{
		PaintTile(i);
	}
}

void AudioFrame::PaintTile(int index)
{
	//qint64 zmienic na T
	const qint64 tileStart = index * tileLenght;
	short previousPcmValue = 0;
	const qint16* base = reinterpret_cast<const qint16*>(buffer.constData());
	const qint16* buffer = base + (tileStart / 2);
	if (buffer > base)
	{
		previousPcmValue = *(buffer - format.channelCount());
	}
	//QLine line(origin, origin);
	const auto previousRealValue = analyser->ConvertInput(previousPcmValue);
	const int originY = ((previousRealValue + 1.0) / 2) * pixmapSize.height();
	const QPoint origin(0, originY);

	QPainter painter(pixmaps[index]);
	painter.fillRect(pixmaps[index]->rect(), Qt::red);
	QPen pen(Qt::white);
	painter.setPen(pen);
	const int numSamples = tileLenght / (2 * format.channelCount());
	QLine line(origin, origin);
	for (size_t i = 0; i < numSamples; i++)
	{
		const qint16* ptr = buffer + i * format.channelCount();
		const int offset = reinterpret_cast<const char*>(ptr) - this->buffer.constData();
		const qint16 pcmValue = *ptr;
		const qreal realValue = analyser->ConvertInput(pcmValue);
		const int x = tilePixelOffset(i * 2 * format.channelCount());
		const int y = ((realValue + 1.0) / 2) * pixmapSize.height();
		line.setP2(QPoint(x, y));
		painter.drawLine(line);
		line.setP1(line.p2());
	}
}

int AudioFrame::tilePixelOffset(qint64 positionOffset) const
{
	const int result = (qreal(positionOffset) / tileLenght) * pixmapSize.width();
	return result;
}

void AudioFrame::CalculateTiles()
{
	int tilesCount;
	if (tileLenght > windowSize)
		tilesCount = 2;
	else
	{
		tilesCount = windowSize / tileLenght + 1;
		if (windowSize % tileLenght)
			++tilesCount;
	}
	pixmaps.assign(tilesCount, 0);
	rect().size();
}

void AudioFrame::CreatePixmaps(QSize widgetSize)
{
	pixmapSize = widgetSize;
	pixmapSize.setWidth(qreal(widgetSize.width()) * tileLenght / windowLenght);
	for (size_t i = 0; i < pixmaps.size(); i++)
	{
		delete pixmaps[i];
		pixmaps[i] = 0;
		pixmaps[i] = new QPixmap(pixmapSize);
	}

}
