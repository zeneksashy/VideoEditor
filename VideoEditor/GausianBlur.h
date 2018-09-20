#pragma once
#include "Effect.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<qscopedpointer.h>
#include<qimage.h>
struct GausianBlurParam
{
	double x;
	double y;
	uint Xsize;
	uint Ysize;
	void Create(double x, double y, uint Xsize, uint Ysize)
	{
		this->x = x;
		this->y = y;
		this->Xsize = Xsize;
		this->Ysize = Ysize;
	}
};

class GausianBlur :
	public Effect
{
public:
	GausianBlur(std::shared_ptr<cv::VideoCapture>, GausianBlurParam);
	GausianBlur();
	void Initialize(std::shared_ptr<cv::VideoCapture>, GausianBlurParam);
	~GausianBlur();
	// Inherited via Effect
	virtual void ExecuteEffect() override;
	//std::vector<QImage> ExecuteGausianBlur();
	std::vector<cv::Mat> ExecuteGausianBlur();
	virtual void Calculate() override;
private:
	GausianBlurParam parameters;
	cv::Mat RGBframe;
	cv::Mat frame;
	std::vector<cv::Mat> data;
	uint framecount;
	std::shared_ptr<cv::VideoCapture> capture;
	std::vector<QImage> convertedFrames;
	std::vector<cv::Mat> pureFrames;
};


