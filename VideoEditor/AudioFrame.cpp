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
	setFixedHeight(60);
	setMinimumWidth(120);
	isSelected = false;
	 scale = 1;
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
	clk = std::clock();
	decoder->start();	
}

void AudioFrame::readBuffer()
{
	auto tempBuff = decoder->read();
	if (isFirstTimeRead)
	{
		this->format = tempBuff.format();
		sampleSize = format.sampleRate();
		sampleLenght = tempBuff.frameCount();
		analyser.reset(recognizer.RrecognizeFrameType(format));
		isFirstTimeRead = false;
	}
	auto data = analyser->LoadDataFromBuffer(tempBuff);
	audioFrames.insert(audioFrames.end(), data.begin(), data.end());
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
	
	if (isSelected)
	{
		pen.setColor(QColor::fromRgb(126, 253, 61));
		painter.setPen(pen);
		painter.drawRoundedRect(0, 0, width()-1, height()-1, 0, 0);
	}
	for (int i = 0; i <audioSamples.size(); i++)
	{
		double plot = 0;
			plot = audioSamples[i]*30;
			QLine line(i, (size.height() / 2)+plot, i, (size.height() / 2) - plot);
			 painter.drawLine(line);
	}
}

void AudioFrame::drawOutline()
{
	isSelected = true;
	repaint();
}

void AudioFrame::mousePressEvent(QMouseEvent *)
{
	drawOutline();
	emit LineSelected(this);
}

void AudioFrame::deleteOutline()
{
	isSelected = false;
	repaint();
}

void AudioFrame::ResizeFrame(int p)
{
	templenght = sampleSize;

	templenght = sampleSize / p;
	if (templenght <= 0)
	{
		int x = templenght;
	}
	audioSamples = fft.RootMeanSquare(audioFrames, templenght);
	fft.Normalize(audioSamples);
	setFixedWidth(audioSamples.size());
	repaint();
}

void AudioFrame::audioDecoded()
{
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - clk;
	double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;
	audioSamples = fft.RootMeanSquare(audioFrames,sampleSize);
	fft.Normalize(audioSamples);
	templenght = lenght = audioSamples.size();
	setFixedWidth(audioSamples.size());
	update();
}

