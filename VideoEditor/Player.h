#pragma once
#include <QMutex>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QThread>
#include "VideoEffect.h"
#include "EffectsContainer.h"
#include <chrono>   
#include <thread>        
#include<qaudiodecoder.h>
#include<qmediaplayer.h>
#include<iostream>
#include<atomic>
#include<queue>

enum MediaType
{
	Video=0,Audio=1,Both=2
};

class SpinLock
{
public:
	void lock()
	{
		while (lck.test_and_set(std::memory_order_acquire))
		{
		}
	}
	void unlock()
	{
		lck.clear(std::memory_order_release);
	}
private:
	std::atomic_flag lck = ATOMIC_FLAG_INIT;
};

class Buffer
{
public:
	Buffer();
	void SetVideoCapture(cv::VideoCapture cap);
	~Buffer();
	void LoadToBuffer();
	bool GetNextFrame(cv::Mat & frame);
	void SetCapturePosition(int pos);
private:
	std::queue<cv::Mat> buff;
	void LoadNext();
	cv::Mat frame;
	cv::Mat newFrame;
	const uint bufferMaxSize = 30;
	cv::VideoCapture capture;
	//SpinLock locker;
	std::mutex locker;
	bool stop;
};
///
///Player class
///
class Player : public QThread
{
	Q_OBJECT
public  slots:
	void setVideoPosition(int pos);
	void recieveTime(std::chrono::nanoseconds);
private slots:
	void MediaStatusChanged(QMediaPlayer::MediaStatus);
signals:
	//Signal to output frame to be displayed
	void processedImage(const QImage &image);
	void videoStopped();
	void positionChanged();
	void EndOfVideo();
	void EndOfMedia();
protected:
	void run();
	void msleep(double ms);
	void msleep(std::chrono::nanoseconds ms);
public:
	void setFrameRate(float);
	float getFrameRate();
	bool isAudioAvaible();
	bool isVideoAvaible();
	//std::shared_ptr<cv::VideoCapture> getVideCapture()const;
	long getFrameCount()const;
	QMediaPlayer* getMediaPlayer() const;
	void setEffect(VideoEffect*);
	void setEffect(std::vector<cv::Mat>);
	//Constructor
	Player(QObject *parent = 0);
	//Destructor
	~Player();
	///Load a video from memory
	bool loadFile(QString filename,MediaType = MediaType::Both);
	void Play();
	void Stop();
	void Pause();
	bool isStopped() const;
	void Deserialize(std::vector<std::string>&);
	friend std::ostream& operator<<(std::ostream& os, const Player& player);
	friend std::istream& operator>>(std::istream& is, const Player& player);
private:
	void CheckMediaType(MediaType);
	QScopedPointer<QMediaPlayer> mediaplayer;
	bool stop;
	QMutex mutex;
	QWaitCondition condition;
	cv::Mat frame;
	float frameRate;
	std::unique_ptr<cv::VideoCapture> capture;
	cv::Mat RGBframe;
	QImage img;
	bool isFirstFrame;
	void PlayEffect();
	bool audio;
	bool video;
	bool isEffectApplied;
	void CaptureNextFrame();
	bool CheckVideo();
	bool CheckAudio();
	bool CheckFile();
	int delay;
	std::chrono::nanoseconds del;
	std::string filename;
	EffectsContainer effects;
	long framceount;
	std::chrono::nanoseconds playerDelay;
	Buffer buffer;
	std::thread worker;
	
};