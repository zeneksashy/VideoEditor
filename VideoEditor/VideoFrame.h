#pragma once

#include <QWidget>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
class VideoFrame : public QWidget
{
	Q_OBJECT

public:
	VideoFrame(QWidget *parent);
	~VideoFrame();
	void paintEvent(QPaintEvent *)override;
	void Initliaize(QString filename);
	QImage loadFrame(long pos);
	void drawOutline();
	void mousePressEvent(QMouseEvent *);
	void deleteOutline();
private:
	cv::Mat frame;
	cv::VideoCapture capture;
	cv::Mat RGBframe;
	long framecount;
	QImage img[3];
	bool isSelected;
};
