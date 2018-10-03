#pragma once
#include "VideoEffect.h"
#include "MediaManager.h"
#include<qimage.h>
struct GausianBlurParam
{
	uint Xsize;
	uint Ysize;
	float x;
	float y;
	void Create(double x, double y, uint Xsize, uint Ysize)
	{
		this->x = x;
		this->y = y;
		this->Xsize = Xsize;
		this->Ysize = Ysize;
	}
	bool operator==(const GausianBlurParam& param)
	{
		if (param.x != this->x)
			return false;
		if (param.y != this->y)
			return false;
		if (param.Xsize != this->Xsize)
			return false;
		if (param.Ysize != this->Ysize)
			return false;
		return true;
	}
};

class GausianBlur :public VideoEffect
{
public:
	GausianBlur(std::shared_ptr<cv::VideoCapture>, GausianBlurParam);
	GausianBlur();
	void Initialize(std::shared_ptr<cv::VideoCapture>, GausianBlurParam);
	void Initialize(GausianBlurParam);
	~GausianBlur();
	std::vector<cv::Mat> ExecuteEffect() override;
	virtual void Calculate(cv::Mat&) override;
	friend std::ostream& operator<<(std::ostream& os, const VideoEffect& effect);
	virtual void Deserialize(std::string) override;
	virtual void Deserialize(std::vector<std::string>&) override;
	GausianBlurParam getParams() const;
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

	// Inherited via VideoEffect
	virtual void Print(std::ostream& out) const override;

	// Inherited via VideoEffect
	

	// Inherited via VideoEffect
	

};