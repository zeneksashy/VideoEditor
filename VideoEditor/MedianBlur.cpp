#include "MedianBlur.h"



MedianBlur::MedianBlur()
{
}


MedianBlur::~MedianBlur()
{
}

void MedianBlur::Initialize(std::shared_ptr<cv::VideoCapture>, uint kernel)
{
	this->capture = capture;
	framecount = capture->get(CV_CAP_PROP_FRAME_COUNT);
	data.resize(framecount);
	this->kernel = kernel;
}

std::vector<cv::Mat> MedianBlur::ExecuteEffect()
{
	return data;
}

void MedianBlur::Calculate()
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
				auto filter = cv::cuda::createMedianFilter(input.type(), kernel);
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
				auto filter = cv::cuda::createMedianFilter(input.type(), kernel);
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
