#include "GausianBlur.h"
#include <ctime>

GausianBlur::GausianBlur(std::shared_ptr<cv::VideoCapture> capture, GausianBlurParam param)
{
	Initialize(capture, param);
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
//	capture->release();
}
std::vector<cv::Mat> GausianBlur::ExecuteEffect()
{
	Calculate();
	return data;
}
//23 seconds size 3x9 y = 1 x = 4.5 on cpu
//3.2 second size 3x9 y =1 x =4.5 on gpu
void GausianBlur::Calculate()
{
	if (CheckParams())
	{
		clock_t start = clock();
		int i = 0;
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
				
			}
			else
			{
				try
				{
					cv::cuda::GpuMat input(frame);
					cv::cuda::GpuMat output;
					auto filter = cv::cuda::createGaussianFilter(input.type(), output.type(), cv::Size(parameters.Xsize, parameters.Ysize), parameters.x, parameters.y);
					filter->apply(input, output);
					data[i] = cv::Mat(output);
				}
				catch (const std::exception& e)
				{
					e.what();
				}
			}
			i++;
		}
		clock_t stop = clock();
		clock_t time = stop - start;
		double result = time / (double)CLOCKS_PER_SEC;
	}
}

bool GausianBlur::CheckParams()
{
	if(parameters.Xsize%2==0 || parameters.Ysize%2==0)
		return false;
	return true;
}
