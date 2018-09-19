#include "AudioFrame.h"
#include <qpaintdevice.h>
#include<qpainter.h>
#include<qbytearray.h>
#include"MediaManager.h"
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
}

AudioFrame::~AudioFrame()
{

}


void AudioFrame::Initialize(QString path)
{
	
	this->path = path;
	decoder.reset(new QAudioDecoder());
	decoder->setSourceFilename(path);
	connect(decoder.data(), &QAudioDecoder::formatChanged, this, &AudioFrame::ChangeFormat);
	connect(decoder.data(), SIGNAL(bufferReady()), this, SLOT(readBuffer()));
	connect(decoder.data(), &QAudioDecoder::finished, this, &AudioFrame::audioDecoded);
	clk = std::clock();
	decoder->start();	
}
void AudioFrame::ChangeFormat(const QAudioFormat& format)
{
	this->format = format;
	sampleSize = format.sampleRate();
	analyser.reset(recognizer.RrecognizeFrameType(format));
}
void AudioFrame::readBuffer()
{
	auto tempBuff = decoder->read();
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
//3 seconds for audiobuffer
//2.4 without pushback // 0,02 sec after ordering private variables // 0,02  after changing qvariant to double
//0.3 second for rms and normalization 
void AudioFrame::audioDecoded()
{
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - clk;
	double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;
	clock_t str = clock();
	audioFrames.shrink_to_fit();
	//sampleSize /= MediaManager::player->getFrameRate();
	audioSamples = fft.RootMeanSquare(audioFrames,sampleSize);
	fft.Normalize(audioSamples);
	clock_t end = clock();
	clock_t time = end - str;
	double time2 = time / (double)CLOCKS_PER_SEC;
	templenght = lenght = audioSamples.size();
	setFixedWidth(audioSamples.size());
	update();
}

