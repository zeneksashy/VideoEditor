#pragma once
#include <QMutex>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QThread>
#include "VideoEffect.h"
#include<qmediaplayer.h>
#include "EffectsContainer.h"
class Player : public QThread
{
	Q_OBJECT


public  slots:
	void setVideoPosition(int pos);
	
signals:
	//Signal to output frame to be displayed
	void processedImage(const QImage &image);
	void positionChanged();
protected:
	void run();
	void msleep(int ms);
public:
	float getFrameRate();
	bool isAudioAvaible();
	bool isVideoAvaible();
	std::shared_ptr<cv::VideoCapture> getVideCapture();
	QMediaPlayer* getMediaPlayer() const;
	void setEffect(VideoEffect*);
	void setEffect(std::vector<cv::Mat>);
	//Constructor
	Player(QObject *parent = 0);
	//Destructor
	~Player();
	//Load a video from memory
	bool loadFile(QString filename);
	//Play the video
	void Play();
	//Stop the video
	void Stop();
	void Pause();
	//check if the player has been stopped
	bool isStopped() const;
	void Deserialize(std::vector<std::string>&);
	friend std::ostream& operator<<(std::ostream& os, const Player& player);
	friend std::istream& operator>>(std::istream& is, const Player& player);
private:
	QScopedPointer<QMediaPlayer> mediaplayer;
	bool stop;
	QMutex mutex;
	QWaitCondition condition;
	cv::Mat frame;
	float frameRate;
	std::shared_ptr<cv::VideoCapture> capture;
	cv::Mat RGBframe;
	QImage img;
	bool isFirstFrame;
	void PlayEffect();
	bool audio;
	bool video;
	bool isEffectApplied;
	bool CheckNextFrame();
	void CaptureNextFrame();
	bool CheckVideo();
	bool CheckAudio();
	bool CheckFile();
	int delay;
	std::string filename;
	EffectsContainer effects;
	VideoEffect* current;
	std::vector<QImage> effectedFrames;
	std::vector<cv::Mat> effectedFramesMat;
};
