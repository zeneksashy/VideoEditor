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
	virtual void Calculate(cv::Mat&) override;
private:
	cv::Mat RGBframe;
	cv::Mat frame;
	uint kernel;
	std::vector<cv::Mat> data;
	uint framecount;
	std::shared_ptr<cv::VideoCapture> capture;
	std::vector<cv::Mat> pureFrames;

	// Inherited via VideoEffect
	virtual void Print(std::ostream & out) const override;

	// Inherited via VideoEffect
	virtual void Deserialize(std::string) override;
};

