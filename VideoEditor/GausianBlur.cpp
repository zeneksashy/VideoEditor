#include "GausianBlur.h"
#include <ctime>

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
std::vector<cv::Mat> GausianBlur::ExecuteGausianBlur()
{
	Calculate();
	return data;
}
//23 seconds size 3x9 y = 1 x = 4.5 on cpu
//3.2 second size 3x9 y =1 x =4.5 on gpu
void GausianBlur::Calculate()
{
	clock_t start= clock();
	int i = 0;
	auto x = cv::getBuildInformation();
	while (capture->read(frame))
	{
		if (frame.channels() == 3) {
			try
			{
				cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
				cv::cuda::GpuMat input(RGBframe);
				cv::cuda::GpuMat output;
				auto filter = cv::cuda::createGaussianFilter(input.type(), output.type(), cv::Size(parameters.Xsize, parameters.Ysize), parameters.x, parameters.y);
				filter->apply(input, output);
				data[i] = cv::Mat(output);
			}
			catch (const std::exception& e)
			{
				e.what();
			}
			
			
			//cv::cuda::GpuMat input;
		
		//	cv::cuda::GpuMat output;
			//input.upload(RGBframe);
			//cv::cuda::Filter* a;
			//cv::cuda::bilateralFilter(frame, RGBframe, 7, 3.4, 1.9);
		//	auto filter = cv::cuda::createGaussianFilter(RGBframe.type(), input.type(), cv::Size(parameters.Xsize, parameters.Ysize), parameters.x, parameters.y);
			//filter->apply(RGBframe, input);
			//cv::GaussianBlur(RGBframe, data[i], cv::Size(parameters.Xsize, parameters.Ysize), parameters.x, parameters.y);
			//auto img = QImage((const unsigned char*)(data[i].data),
			//	RGBframe.cols, RGBframe.rows, QImage::Format_RGB32);
		//	convertedFrames[i] = img;
		}
		else
		{
			cv::GaussianBlur(RGBframe, RGBframe, cv::Size(parameters.Xsize, parameters.Ysize), parameters.x, parameters.y);
			convertedFrames[i] = QImage((const unsigned char*)(frame.data),
				frame.cols, frame.rows, QImage::Format_Indexed8);
		}
		i++;
	}
	clock_t stop = clock();
	clock_t time = stop - start;
	double result = time / (double)CLOCKS_PER_SEC;
}
