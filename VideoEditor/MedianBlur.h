#pragma once
#include "VideoEffect.h"
#include <ctime>

class MedianBlur :public VideoEffect
{
public:
	MedianBlur();
	~MedianBlur();
	void Initialize(std::shared_ptr<cv::VideoCapture>, uint kernel);
	// Inherited via VideoEffect
	virtual std::vector<cv::Mat> ExecuteEffect() override;
	virtual void Calculate() override;
private:
	cv::Mat RGBframe;
	cv::Mat frame;
	uint kernel;
	std::vector<cv::Mat> data;
	uint framecount;
	std::shared_ptr<cv::VideoCapture> capture;
	std::vector<cv::Mat> pureFrames;
};

