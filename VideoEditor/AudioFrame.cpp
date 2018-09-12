#include "AudioFrame.h"
#include <qpaintdevice.h>
#include<qpainter.h>
#include<qbytearray.h>
#include<AudioRecognition.h>
AudioFrame::AudioFrame(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	setMinimumHeight(50);
}

AudioFrame::~AudioFrame()
{
}

void AudioFrame::Initialize(QString path)
{
	this->path = path;
	decoder.reset(new QAudioDecoder());
	decoder->setSourceFilename(path);
	connect(decoder.data(), SIGNAL(bufferReady()), this, SLOT(readBuffer()));
	connect(decoder.data(), &QAudioDecoder::finished, this, &AudioFrame::audioDecoded);
	decoder->start();
	
	tileLenght = 4096;
	
	//CreatePixmaps(rect().size());
}
void AudioFrame::readBuffer()
{
	auto tempBuff = decoder->read();
	//if (isFirstTimeRead)
//	{
	//	
	//	
	//	windowSize = audioLength(format, windowsDuration);
	//	//CalculateTiles();
	//	isFirstTimeRead = false;
//	}
	this->format = tempBuff.format();
	bufferbytecount = tempBuff.byteCount();
	auto sample = this->format.sampleRate();
	analyser.reset(recognizer.RrecognizeFrameType(tempBuff, format));
	QAudioBuffer::S16U *frames = tempBuff.data<QAudioBuffer::S16U>();
	for (size_t i = 0; i < tempBuff.frameCount(); i++)
	{
		auto wat = tempBuff.frameCount();
		double x = frames[i].average();
		double left = frames[i].left;
		double right = frames[i].right;

		double amplitude = (double)frames[i].average() / 32767;
		double temp = 0;
		if (amplitude < 0)
		{
			amplitude *= -1;
			temp = std::log10(amplitude);
		}
		else if(amplitude > 0)
		{
			temp = std::log10(amplitude);
		}
		double db = 20 *temp;
		//db = 24*(db-1)
		//db = qMax(qreal(0.0), db);
		//db = qMin(qreal(1.0), db);
		audioFrames.push_back(db);
	}
	buffers.push_back(tempBuff);
}
void AudioFrame::Initialize(AudioAnalyser *analyser, const QAudioFormat & format, qint64 audioBufferSize)
{
	this -> format = format;
	//tileLenght = audioBufferSize;
	this->analyser.reset(analyser);
	

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
	this->data = buffer;
	for (size_t i = 0; i < pixmaps.size(); i++)
	{
		PaintTile(i);
	}
	update();
	emit LineDrawn(this);
	
}
int windowPixelOffset(qint64 positionOffset)
{
	const int result = (qreal(positionOffset) / 1500);
	return result;
}
void AudioFrame::paintEvent(QPaintEvent*)
{

	QPainter painter(this);
	painter.fillRect(rect(), Qt::red);
	int destLeft = 0;
	int destRight = 20;
	int pos = 0;
	QSize size(rect().size());
	const int spectrWidth = 1000;
	const int spectrHeight = 500;
	QPixmap spectrPixmap(size);
	QPainter p(&spectrPixmap);
	QPen pen(Qt::blue);
	painter.setPen(pen);
	int i = 0;
	//rect().setWidth(audioSamples.size());
	for (int ir = 0; ir <audioSamples.size(); ir++)
	{
		double plot = 0;
			plot = audioSamples[ir]*25;
			QLine line(i, (size.height() / 2)+plot, i, (size.height() / 2) - plot);
			// QLine line(i, size.height() / 2+plot, i, plot);
			 painter.drawLine(line);
			 //i+=linesize;
			 ++i;
		
	
	}
}
void AudioFrame::PaintTile(int index)
{
	//qint64 zmienic na T
	const qint64 tileStart = index * tileLenght;
	short previousPcmValue = 0;
	
	const qint16* base = reinterpret_cast<const qint16*>(data.constData());
	const qint16* buffer = base + (tileStart / 2);
	if (buffer > base)
	{
		previousPcmValue = *(buffer - format.channelCount());
	}
	const auto previousRealValue = analyser->ConvertInput(previousPcmValue);
	const int originY = ((previousRealValue + 1.0) / 2) * pixmapSize.height();
	const QPoint origin(0, originY);
	QPainter painter(pixmaps[index]);
	painter.fillRect(pixmaps[index]->rect(), Qt::blue);
	QPen pen(Qt::green);
	painter.setPen(pen);
	const int numSamples = tileLenght / (2 * format.channelCount());
	QLine line(origin, origin);
	int x = 0;
	for (size_t i = 0; i < numSamples; i++)
	{
		const qint16* ptr = buffer + i * format.channelCount();
		//const int offset = reinterpret_cast<const char*>(ptr) - this->data.constData();
		const qint16 pcmValue = *ptr;
		const qreal realValue = analyser->ConvertInput(pcmValue);
		// int x = tilePixelOffset(i * 2 * format.channelCount());
		x += 5;

		 int y = ((realValue + 1.0) / 2) * pixmapSize.height();
	//	 y +=x;
	
		line.setP2(QPoint(x, y));
		painter.drawLine(line);
		line.setP1(line.p2());
	}

}
void AudioFrame::smth(int index)
{
	

}
void AudioFrame::audioDecoded()
{
	singlebufferLenght = PowerOfTwo<12>::Result *(format.sampleSize() / 8)*format.channelCount();
	for each (auto buffer in buffers)
	{
		data.append(QByteArray::fromRawData(buffer.constData<char>(), singlebufferLenght));
	}
	rms();
	nomralize();
	//tileLenght = data.size();
	smth(0);
	update();
	//PaintTiles(data.size(), data);
	emit LineDrawn(this);
}

void AudioFrame::ReadFormat()
{
	//this->decoder
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
	CreatePixmaps(rect().size());
}

void AudioFrame::CreatePixmaps(QSize widgetSize)
{
	pixmapSize = widgetSize;
	pixmapSize.setWidth(qreal(widgetSize.width()) * tileLenght / windowSize);
	for (size_t i = 0; i < pixmaps.size(); i++)
	{
		delete pixmaps[i];
		pixmaps[i] = 0;
		pixmaps[i] = new QPixmap(pixmapSize);
	}

}

void AudioFrame::nomralize()
{
	auto vmax = std::max_element(audioSamples.begin(), audioSamples.end());
	double max = *vmax;
	auto vmin = std::min_element(audioSamples.begin(), audioSamples.end());
	double min = *vmin;
	for (size_t i = 0; i < audioSamples.size(); i++)
	{
		auto temp = min * -1;
		audioSamples[i] += temp;
	}
	for (size_t i = 0; i < audioSamples.size(); i++)
	{
		audioSamples[i] /= (max - min);
	}
}
// delete 4096 and add other number
void AudioFrame::rms()
{
	auto size = audioFrames.size()/4096;
	int k = 0;
	for (size_t i = 1; i <= size; i++)
	{
		double temp=0;
		for (size_t j = k; j < 4096*i; j++)
		{
			temp += audioFrames[j]*audioFrames[j];
		}
		temp /= 4096;
		audioSamples.push_back(std::sqrt(temp));

		k += 4096;
	}
	
}
