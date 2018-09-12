#include "AudioFrame.h"
#include <qpaintdevice.h>
#include<qpainter.h>
#include<qbytearray.h>
#include<AudioRecognition.h>
AudioFrame::AudioFrame(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setMinimumHeight(60);
	
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
}

void AudioFrame::readBuffer()
{
	auto tempBuff = decoder->read();
	if (isFirstTimeRead)
	{
		this->format = tempBuff.format();
		sampleLenght = format.sampleSize();
		analyser.reset(recognizer.RrecognizeFrameType(tempBuff, format));
	}
	QAudioBuffer::S16U *frames = tempBuff.data<QAudioBuffer::S16U>();
	for (size_t i = 0; i < tempBuff.frameCount(); i++)
	{
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
		audioFrames.push_back(db);
	}
}

void AudioFrame::Initialize(AudioAnalyser *analyser, const QAudioFormat & format, qint64 audioBufferSize)
{
	this -> format = format;
	//tileLenght = audioBufferSize;
	this->analyser.reset(analyser);
	

}
void AudioFrame::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	painter.fillRect(rect(), Qt::gray);
	QSize size(rect().size());
	QPixmap spectrPixmap(size);
	QPainter p(&spectrPixmap);
	QPen pen(Qt::blue);
	painter.setPen(pen);
	setMinimumWidth(audioSamples.size());
	for (int i = 0; i <audioSamples.size(); i++)
	{
		double plot = 0;
			plot = audioSamples[i]*30;
			QLine line(i, (size.height() / 2)+plot, i, (size.height() / 2) - plot);
			 painter.drawLine(line);
	}
}

void AudioFrame::audioDecoded()
{
	rms();
	nomralize();
	update();
	emit LineDrawn(this);
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
// delete 4096 and add variable number
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
