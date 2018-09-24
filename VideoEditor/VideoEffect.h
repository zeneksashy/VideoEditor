#pragma once
#include <opencv2/core/core.hpp>
class VideoEffect
{
public:
	VideoEffect() {};
	virtual ~VideoEffect() {};
	virtual std::vector<cv::Mat> ExecuteEffect()=0;
	virtual void Calculate() = 0;
};

