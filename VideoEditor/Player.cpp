#include "Player.h"
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <thread>        
#include <chrono>   
#include<qmediaplayer.h>
#include <QFileDevice>
#include<qiodevice.h>
#include <qbuffer.h>
#include<qfile.h>
#include<qmediametadata.h>
Player::Player(QObject *parent)
	: QThread(parent)
{
	mediaplayer.reset(new QMediaPlayer);
	stop = true;
	capture.reset(new cv::VideoCapture);
	isEffectApplied = false;
}
bool Player::loadFile(QString filename) 
{
	capture->open(filename.toStdString());
	if (CheckFile())
	{
		mediaplayer->setMedia(QUrl::fromLocalFile(filename));
	    audio = CheckAudio();
		video = CheckVideo();
		if(video)
		{
			frameRate = (int)capture->get(CV_CAP_PROP_FPS);
			delay = (1000 / frameRate);
		}
		return true;
	}
	else
		return false;
}
void Player::Play()
{
	if (!isRunning()) {
		if (isStopped()) {
			stop = false;
		}
		if(video)
		start(LowPriority);
		if (audio)
			mediaplayer->play();
	}
}
bool Player::CheckFile()
{
	if (capture->isOpened())
		return true;
	return false;

}
bool Player::CheckVideo()
{
	if (capture->read(frame))
	{
		return true;
		capture->set(cv::CAP_PROP_POS_FRAMES, 0);
	}
	stop = true;
	return false;
}
bool Player::CheckAudio()
{
	if (mediaplayer->error() == QMediaPlayer::NoError)
		return true;
	return false;
}
void Player::setVideoPosition(int pos)
{
	Pause();
	mediaplayer->setPosition(pos);
	capture->set(CV_CAP_PROP_POS_MSEC, pos);
	Play();
}

void Player::run()
{
	int i=0;
	while (!stop)
	{
		if (isEffectApplied)
			PlayEffect(i);
		else
			CaptureNextFrame();
		++i;
	}
	
}

void Player::Stop()
{
	capture->set(cv::CAP_PROP_POS_FRAMES, 0);
	mediaplayer->stop();
	stop = true;
}

void Player::Pause()
{
	mediaplayer->pause();
	stop = true;
}

void Player::PlayEffect(int i)
{
	if (CheckNextFrame())
	{
		current->Calculate(frame);
		cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
		img = QImage((const unsigned char*)(RGBframe.data),
		RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
		emit processedImage(img);
		emit positionChanged();
		this->msleep(delay);
	}

	//if (i == effectedFramesMat.size())
	//	stop = true;
	//else
	//{
	//	img = QImage((const unsigned char*)(effectedFramesMat[i].data),
	//		effectedFramesMat[i].cols, effectedFramesMat[i].rows, QImage::Format_RGB888);
	//	emit processedImage(img);
	//	emit positionChanged();
	//	this->msleep(delay);
	//}
	
}

bool Player::CheckNextFrame()
{
	if (!capture->read(frame))
	{
		stop = true;
		return false;
	}
	return true;
}
void Player::CaptureNextFrame()
{
	if (CheckNextFrame())
	{
		if (frame.channels() == 3) {
			cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
			img = QImage((const unsigned char*)(RGBframe.data),
				RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
		}
		else
		{
			img = QImage((const unsigned char*)(frame.data),
				frame.cols, frame.rows, QImage::Format_Indexed8);
		}
		emit processedImage(img);
		emit positionChanged();
		this->msleep(delay);
	}
}

void Player::msleep(int ms) {
	std::this_thread::sleep_for(std::chrono::nanoseconds((ms % 1000) * 1000 * 1000));
}


int Player::getFrameRate()
{
	return frameRate;
}

bool Player::isAudioAvaible()
{
	return audio;
}

bool Player::isVideoAvaible()
{
	return video;
}

std::shared_ptr<cv::VideoCapture> Player::getVideCapture()
{
	return capture;
}

QMediaPlayer* Player::getMediaPlayer() const
{
	return mediaplayer.data();
}
void Player::setEffect(VideoEffect* effect)
{
	current = effect;
	isEffectApplied = true;
}
void Player::setEffect(std::vector<cv::Mat> frames)
{
	effectedFramesMat = frames;
	isEffectApplied = true;
	//isEffectApplied = true;
	//const QImage image = frames[35];
	//emit processedImage(image);
}
bool Player::isStopped() const {
	return this->stop;
}

Player::~Player()
{
	mutex.lock();
	stop = true;
	capture->release();
	condition.wakeOne();
	mutex.unlock();
	wait();
}
