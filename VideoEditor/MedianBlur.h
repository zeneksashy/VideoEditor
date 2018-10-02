#pragma once
#include "VideoEffect.h"
#include <ctime>
#include<map>
class MedianBlur :public VideoEffect
{
public:
	MedianBlur();
	~MedianBlur();
	void Initialize(std::shared_ptr<cv::VideoCapture>, uint kernel);
	// Inherited via VideoEffect
	virtual std::vector<cv::Mat> ExecuteEffect() override;
	virtual void Calculate(cv::Mat&) override;
	virtual void Deserialize(std::string) override;
	uint getKernel();
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
	
};

