#include "AudioTrack.h"

AudioTrack::AudioTrack(QWidget *parent):MediaTrack(parent),lenght(0)
{
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setFixedHeight(32);
	setMinimumWidth(120);
	isSelected = false;
}

AudioTrack::~AudioTrack()
{

}

void AudioTrack::Initialize(QString path)
{
	setPlayer(path, MediaType::Audio);
	this->path = path;
	decoder.reset(new QAudioDecoder());
	decoder->setSourceFilename(path);
	connect(decoder.data(), &QAudioDecoder::formatChanged, this, &AudioTrack::ChangeFormat);
	connect(decoder.data(), SIGNAL(bufferReady()), this, SLOT(readBuffer()));
	connect(decoder.data(), &QAudioDecoder::finished, this, &AudioTrack::audioDecoded);
	decoder->start();
}
void AudioTrack::ChangeFormat(const QAudioFormat& format)
{
	this->format = format;
	sampleSize = format.sampleRate();
	analyser.reset(recognizer.RrecognizeFrameType(format));
}
void AudioTrack::readBuffer()
{
	auto tempBuff = decoder->read();
	auto data = analyser->LoadDataFromBuffer(tempBuff);
	audioFrames.insert(audioFrames.end(), data.begin(), data.end());
}

void AudioTrack::Initialize(AudioAnalyser *analyser, const QAudioFormat & format, qint64 audioBufferSize)
{
	this -> format = format;
	this->analyser.reset(analyser);
}
void AudioTrack::paintEvent(QPaintEvent*)
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
	for (int i = 0; i <templenght; i++)
	{
		double plot = 0;
		plot = audioSamples[i]*30;
		QLine line(i, (size.height() / 2)+plot, i, (size.height() / 2) - plot);
		painter.drawLine(line);
	}
}

void AudioTrack::drawOutline()
{
	isSelected = true;
	repaint();
}

void AudioTrack::deleteOutline()
{
	isSelected = false;
	repaint();
}

void AudioTrack::ResizeFrame(int p)
{
	templenght = sampleSize;
	templenght = sampleSize / p;
	if (templenght <= 0)
	{
		int x = templenght;
	}
	audioSamples = fft.RootMeanSquare(audioFrames, (double)templenght);
	fft.Normalize(audioSamples);
	templenght = lenght * p;
	setFixedWidth(templenght);
	repaint();
}
//3 seconds for audiobuffer
//2.4 without pushback // 0,02 sec after ordering private variables // 0,02  after changing qvariant to double
//0.3 second for rms and normalization 
void AudioTrack::audioDecoded()
{
	audioFrames.shrink_to_fit();
	audioSamples = fft.RootMeanSquare(audioFrames,(int)sampleSize);
	fft.Normalize(audioSamples);
	templenght = lenght = audioSamples.size();
	setFixedWidth(audioSamples.size());
	update();
}

