#pragma once
#include <QMutex>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QThread>
#include<qmediaplayer.h>
class Player : public QThread
{
	Q_OBJECT

private:
	QScopedPointer<QMediaPlayer> mediaplayer;
	bool stop;
	QMutex mutex;
	QWaitCondition condition;
	cv::Mat frame;
	int frameRate;
	cv::VideoCapture capture;
	cv::Mat RGBframe;
	QImage img;
	bool audio;
	bool video;
	bool CheckNextFrame();
	void CaptureNextFrame();
	bool CheckVideo();
	bool CheckAudio();
	bool CheckFile();
	int delay;
public  slots:
	void setVideoPosition(int pos);
	
signals:
	//Signal to output frame to be displayed
	void processedImage(const QImage &image);
	void positionChanged(qint64 pos);
protected:
	void run();
	void msleep(int ms);
public:
	void getMediaPosition(qint64);
	bool isAudioAvaible();
	bool isVideoAvaible();
	QMediaPlayer* getMediaPlayer() const;
	void effect();
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

};
