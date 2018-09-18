#pragma once

#include <QWidget>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include"MediaFrame.h"
class VideoFrame : public QWidget,public MediaFrame
{
	Q_OBJECT

public:
	VideoFrame(QWidget *parent);
	~VideoFrame();
	void paintEvent(QPaintEvent *)override;
	void Initliaize(QString filename);
	QImage loadFrame(long pos);
	void drawOutline() override;
	void mousePressEvent(QMouseEvent *);
	void ResizeFrame(int) override;
	void deleteOutline() override;
signals:
	void LineSelected(VideoFrame*);
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
