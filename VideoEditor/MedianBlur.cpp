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

void MedianBlur::Deserialize(std::string path)
{
	std::string tempstring = path;
	std::string temp = "";
	std::vector<std::string> strngs;
	int i = 0;
	char next;
	std::map<char, int> hashes;
	while (i < tempstring.length())
	{
		if (tempstring[i] == '#')
		{
			if (tempstring[i + 1] != '#')
			{
				auto it = hashes.find(tempstring[i + 1]);
				if (it != hashes.end())
				{
					hashes[tempstring[i + 1]] += 1;
					if (hashes[tempstring[i + 1]] == 2)
					{
						hashes[tempstring[i + 1]] = 1;
						if (temp != "")
							strngs.emplace_back(temp);
						temp = "";
					}
					else
					{
						++i;
					}

				}
				else
				{
					hashes[tempstring[i + 1]] = 1;
				}
			}
			if (temp != "")
				strngs.emplace_back(temp);
			temp = "";
		}
		else
		{
			temp += tempstring[i];
		}
		++i;
	}
	for (size_t i = 0; i < strngs.size(); i++)
	{
		if (strngs[i] == "Kernel")
		{
			kernel = std::stoi(strngs[i + 1]);
			break;;
		}
	}
}

uint MedianBlur::getKernel()
{
	return kernel;
}
