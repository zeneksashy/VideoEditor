#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/core/cuda.hpp"
#include "cudaimgproc/include/opencv2/cudaimgproc.hpp"
#include <opencv2/core/cuda_types.hpp>
#include <cudacodec/include/opencv2/cudacodec.hpp>
#include <cudafilters/include/opencv2/cudafilters.hpp>
#include "opencv2/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include<qscopedpointer.h>

class VideoEffect
{
public:
	VideoEffect() {};
	virtual ~VideoEffect() {};
	virtual std::vector<cv::Mat> ExecuteEffect()=0;
	virtual void Calculate(cv::Mat&) = 0;
	 friend std::ostream& operator<<(std::ostream& os, const VideoEffect& effect);
	 virtual void Deserialize(std::string) = 0;
	 virtual void Deserialize(std::vector<std::string>&) = 0;
protected:
	virtual void Print(std::ostream& out) const = 0;
};

