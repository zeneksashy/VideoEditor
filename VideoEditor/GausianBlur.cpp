#include "GausianBlur.h"


GausianBlur::GausianBlur(std::shared_ptr<cv::VideoCapture> capture, GausianBlurParam param)
{
	this->capture = capture;
	framecount = capture->get(CV_CAP_PROP_FRAME_COUNT);
	convertedFrames.resize(framecount);
	data.resize(framecount);
	this->parameters = param;
	
}

GausianBlur::GausianBlur()
{
}


void GausianBlur::Initialize(std::shared_ptr<cv::VideoCapture> capture, GausianBlurParam param)
{
	this->capture = capture;
	framecount = capture->get(CV_CAP_PROP_FRAME_COUNT);
	convertedFrames.resize(framecount);
	data.resize(framecount);
	this->parameters = param;
}

GausianBlur::~GausianBlur()
{
	capture->release();
}

void GausianBlur::ExecuteEffect()
{
}

//std::vector<QImage> GausianBlur::ExecuteGausianBlur()
//{
//	Calculate();
//	return convertedFrames;
//}
std::vector<cv::Mat> GausianBlur::ExecuteGausianBlur()
{
	Calculate();
	return data;
}

void GausianBlur::Calculate()
{
	int i = 0;
	while (capture->read(frame))
	{
		if (frame.channels() == 3) {
			cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
			cv::GaussianBlur(RGBframe, data[i], cv::Size(parameters.Xsize, parameters.Ysize), parameters.x, parameters.y);
			auto img = QImage((const unsigned char*)(data[i].data),
				RGBframe.cols, RGBframe.rows, QImage::Format_RGB32);
			convertedFrames[i] = img;
		}
		else
		{
			cv::GaussianBlur(RGBframe, RGBframe, cv::Size(parameters.Xsize, parameters.Ysize), parameters.x, parameters.y);
			convertedFrames[i] = QImage((const unsigned char*)(frame.data),
				frame.cols, frame.rows, QImage::Format_Indexed8);
		}
		i++;
	}
}
