#pragma once

#include <QWidget>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include"MediaTrack.h"
class VideoTrack : public MediaTrack
{
	Q_OBJECT
public:
	VideoTrack(QWidget *parent);
	~VideoTrack();
	void paintEvent(QPaintEvent *)override;
	void Initliaize(QString filename);
	QImage loadFrame(long pos);
	void drawOutline() override;
	void ResizeFrame(int) override;
	void deleteOutline() override;
signals:
	void LineSelected(VideoTrack*);
private:
	int scale;
	cv::Mat frame;
	int templenght;
	cv::VideoCapture capture;
	cv::Mat RGBframe;
	long framecount;
	int framerate;
	int lenght;
	QImage img[3];
	bool isSelected;
};
