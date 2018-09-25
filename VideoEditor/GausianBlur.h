#pragma once
#include "VideoEffect.h"

#include<qimage.h>
struct GausianBlurParam
{
	uint Xsize;
	uint Ysize;
	double x;
	double y;
	void Create(double x, double y, uint Xsize, uint Ysize)
	{
		this->x = x;
		this->y = y;
		this->Xsize = Xsize;
		this->Ysize = Ysize;
	}
};

class GausianBlur :public VideoEffect
{
public:
	GausianBlur(std::shared_ptr<cv::VideoCapture>, GausianBlurParam);
	GausianBlur();
	void Initialize(std::shared_ptr<cv::VideoCapture>, GausianBlurParam);
	~GausianBlur();
	std::vector<cv::Mat> ExecuteEffect() override;
	virtual void Calculate(cv::Mat&) override;
private:
	cv::Mat RGBframe;
	cv::Mat frame;
	bool CheckParams();
	uint framecount;
	GausianBlurParam parameters;
	std::vector<cv::Mat> data;
	std::shared_ptr<cv::VideoCapture> capture;
	std::vector<QImage> convertedFrames;
	std::vector<cv::Mat> pureFrames;
};