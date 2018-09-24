#pragma once
#include "VideoEffect.h"

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

class GausianBlur :public VideoEffect
{
public:
	GausianBlur(std::shared_ptr<cv::VideoCapture>, GausianBlurParam);
	GausianBlur();
	void Initialize(std::shared_ptr<cv::VideoCapture>, GausianBlurParam);
	~GausianBlur();
	std::vector<cv::Mat> ExecuteEffect() override;
	virtual void Calculate() override;
private:
	bool CheckParams();
	GausianBlurParam parameters;
	cv::Mat RGBframe;
	cv::Mat frame;
	std::vector<cv::Mat> data;
	uint framecount;
	std::shared_ptr<cv::VideoCapture> capture;
	std::vector<QImage> convertedFrames;
	std::vector<cv::Mat> pureFrames;
};


