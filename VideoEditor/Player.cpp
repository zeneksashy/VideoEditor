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
Player::Player(QObject *parent)
	: QThread(parent)
{
	mediaplayer.reset(new QMediaPlayer);
	stop = true;
}
bool Player::loadVideo(QString filename) {
	capture.open(filename.toStdString());
	
	if (capture.isOpened())
	{
		frameRate = (int)capture.get(CV_CAP_PROP_FPS);
		delay = (1000 / frameRate);
		mediaplayer->setMedia(QUrl::fromLocalFile(filename));
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
		mediaplayer->play();
		start(LowPriority);
	}
}

void Player::setVideoPosition(int pos)
{
	Pause();
	mediaplayer->setPosition(pos);
	capture.set(CV_CAP_PROP_POS_MSEC, pos);
	Play();
}

void Player::run()
{
	while (!stop)
	{
		CaptureNextFrame();
	}
}

void Player::Stop()
{
	capture.set(cv::CAP_PROP_POS_FRAMES, 0);
	mediaplayer->stop();
	stop = true;
}

void Player::Pause()
{
	mediaplayer->pause();
	stop = true;
}

void Player::CaptureNextFrame()
{
	if (!capture.read(frame))
	{
		stop = true;
	}
	if (frame.channels() == 3) {
		cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
		//cv::GaussianBlur(RGBframe, RGBframe, cv::Size(15, 5), 10.3, 9.2);
		img = QImage((const unsigned char*)(RGBframe.data),
			RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
	}
	else
	{
		//cv::GaussianBlur(frame, frame, cv::Size(5, 3), 2.3, 1.2);
		img = QImage((const unsigned char*)(frame.data),
			frame.cols, frame.rows, QImage::Format_Indexed8);
	}
	emit processedImage(img);
	this->msleep(delay);
}

void Player::msleep(int ms) {
	std::this_thread::sleep_for(std::chrono::nanoseconds((ms % 1000) * 1000 * 1000));
}

QMediaPlayer* Player::getMediaPlayer() const
{
	return mediaplayer.data();
}

void Player::effect()
{
	/*exit();
	cv::GaussianBlur(RGBframe, RGBframe, cv::Size(5, 3), 2.3, 1.2);
	Play();*/
	
}

bool Player::isStopped() const {
	return this->stop;
}

Player::~Player()
{
	mutex.lock();
	stop = true;
	capture.release();
	condition.wakeOne();
	mutex.unlock();
	wait();
}
