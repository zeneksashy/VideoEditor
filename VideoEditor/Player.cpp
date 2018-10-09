#include "Player.h"
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <thread>        
#include<qaudiodecoder.h>
#include<qmediaplayer.h>
#include <QFileDevice>
#include<qiodevice.h>
#include <qbuffer.h>
#include<qfile.h>
#include<qmediametadata.h>
#include<ctime>
#include<iostream>
Player::Player(QObject *parent)
	: QThread(parent)
{
	mediaplayer.reset(new QMediaPlayer);
	stop = true;
	capture.reset(new cv::VideoCapture);
	isEffectApplied = false;
	isFirstFrame = true;
	playerDelay = chrono::nanoseconds(0);
}
bool Player::loadFile(QString filename) 
{
	capture->open(filename.toStdString());
	if (CheckFile())
	{
		mediaplayer->setMedia(QUrl::fromLocalFile(filename));
		framceount =(int)capture->get(cv::CAP_PROP_FRAME_COUNT);
		audio = CheckAudio();
		video = CheckVideo();
		if(video)
		{
			capture->set(cv::CAP_PROP_BUFFERSIZE,12);
			
			//pureFrames.resize((int)capture->get(cv::CAP_PROP_FRAME_COUNT));
			//pureImage.resize((int)capture->get(cv::CAP_PROP_FRAME_COUNT));
			frameRate = capture->get(CV_CAP_PROP_FPS);
			delay = (1000 / frameRate);
			auto mili = std::chrono::milliseconds(delay);
			del = std::chrono::duration_cast<std::chrono::nanoseconds> (mili);
			/*for (size_t i = 0; i < pureFrames.size(); i++)
			{
				capture->read(frame);
				cv::cvtColor(frame, pureFrames[i], CV_BGR2RGB);
				pureImage[i] = QImage((const unsigned char*)(pureFrames[i].data),
					pureFrames[i].cols, pureFrames[i].rows, QImage::Format_RGB888);
			}*/
		}
		this->filename = filename.toStdString();
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
		if (video)
			start(LowPriority);
		if (audio)
		{
			
		}
			
			//mediaplayer->play();
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

void Player::recieveTime(std::chrono::nanoseconds nano)
{
	playerDelay = nano;
}

void Player::run()
{
	mediaplayer->play();
	auto nstart = std::chrono::high_resolution_clock::now();
	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();
	auto nano = std::chrono::duration_cast<chrono::nanoseconds>(end - start);
	while (true)
	{
		start = std::chrono::high_resolution_clock::now();
		if (isEffectApplied)
		{
			PlayEffect();
		}
		else
		{
			CaptureNextFrame();
		}
		if (stop)
			break;
		end = std::chrono::high_resolution_clock::now();
		nano = std::chrono::duration_cast<chrono::nanoseconds>(end - start);
		this->msleep((del - nano) -chrono::nanoseconds(1077152)-playerDelay); //1077152 is time of singe while iteration 
	}
	auto nend = std::chrono::high_resolution_clock::now();
	auto nnano = std::chrono::duration_cast<chrono::milliseconds>(nend - nstart);
	cout << "execution time "<< nnano.count() << "\n";
	//13872
	//13800
	// should be 13480
}

void Player::Stop()
{
	capture->set(cv::CAP_PROP_POS_FRAMES, 0);
	mediaplayer->stop();
	stop = true;
	emit videoStopped();
}

void Player::Pause()
{
	mediaplayer->pause();
	stop = true;
}

void Player::PlayEffect()
{
	if (CheckNextFrame())
	{
		effects.Run(frame);
		cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
		img = QImage((const unsigned char*)(RGBframe.data),
		RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
		emit processedImage(std::move(img));
		emit positionChanged();
	}
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
		cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
		img = QImage((const unsigned char*)(RGBframe.data), RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
		emit processedImage(std::move(img));
		emit positionChanged();
	}	
}

void Player::msleep(double ms) 
{
	std::this_thread::sleep_for(std::chrono::nanoseconds(((int)ms % 1000) * 1000 * 1000));
}

void Player::msleep(std::chrono::nanoseconds ms)
{
	std::this_thread::sleep_for(ms);
}

void Player::setFrameRate(float rate)
{
	// dynamic time warp ?
}

float Player::getFrameRate()
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
	effects.AddEffect(effect);
	isEffectApplied = true;
}
void Player::setEffect(std::vector<cv::Mat> frames)
{
//	effectedFramesMat = frames;
	isEffectApplied = true;
}
bool Player::isStopped() const {
	return this->stop;
}

void Player::Deserialize(std::vector<std::string>&x)
{
	effects.Deserialize(x);
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

std::ostream & operator<<(std::ostream & os, const Player & player)
{
	os << player.effects;
	return os;
}

std::istream & operator>>(std::istream & is, const Player & player)
{
	
	// TODO: insert return statement here
	return is;
}
