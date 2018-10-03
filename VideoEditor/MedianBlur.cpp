#include "MedianBlur.h"
#include "MediaManager.h"


MedianBlur::MedianBlur()
{
}


MedianBlur::~MedianBlur()
{
}

void MedianBlur::Initialize(uint kernel)
{
	this->kernel = kernel;
}

std::vector<cv::Mat> MedianBlur::ExecuteEffect()
{
	return data;
}

void MedianBlur::Calculate(cv::Mat &)
{
	//clock_t start = clock();
	//int i = 0;
	//while (capture->read(frame))
	//{
	//	if (frame.channels() == 3) {
	//		try
	//		{
	//			cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
	//			cv::cuda::GpuMat input(RGBframe);
	//			cv::cuda::GpuMat output;
	//			auto filter = cv::cuda::createMedianFilter(input.type(), kernel);
	//			filter->apply(input, output);
	//			data[i] = cv::Mat(output);
	//		}
	//		catch (const std::exception& e)
	//		{
	//			e.what();
	//		}
	//	}
	//	else
	//	{
	//		try
	//		{
	//			cv::cuda::GpuMat input(frame);
	//			cv::cuda::GpuMat output;
	//			auto filter = cv::cuda::createMedianFilter(input.type(), kernel);
	//			filter->apply(input, output);
	//			data[i] = cv::Mat(output);
	//		}
	//		catch (const std::exception& e)
	//		{
	//			e.what();
	//		}
	//	}
	//	i++;
	//}
	//clock_t stop = clock();
	//clock_t time = stop - start;
	//double result = time / (double)CLOCKS_PER_SEC;
}

void MedianBlur::Print(std::ostream & out) const
{
	out << "#MedianBlur#" << "#Kernel#" << kernel << "#K" << "#M";
}

void MedianBlur::Deserialize(std::vector<std::string>&strngs)
{
	for (size_t i = 0; i < strngs.size(); i++)
	{
		if (strngs[i] == "Kernel")
		{
			kernel = std::stoi(strngs[i + 1]);
			break;;
		}
	}
}

void MedianBlur::Deserialize(std::string value)
{
	auto strngs = MediaManager::getValuesFromString(value);
	Deserialize(strngs);
}

uint MedianBlur::getKernel()
{
	return kernel;
}
