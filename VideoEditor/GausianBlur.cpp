#include "GausianBlur.h"
#include <ctime>

GausianBlur::GausianBlur()
{
}

void GausianBlur::Initialize(GausianBlurParam param)
{
	this->parameters = param;
}

GausianBlur::~GausianBlur()
{
}
std::vector<cv::Mat> GausianBlur::ExecuteEffect()
{
	//Calculate();
	return std::vector<cv::Mat>();
}
//23 seconds size 3x9 y = 1 x = 4.5 on cpu
//3.2 second size 3x9 y =1 x =4.5 on gpu
void GausianBlur::Calculate(cv::Mat& frame)
{
	clock_t start = clock();
	if (CheckParams())
	{
		cv::cuda::Stream stream;
		cv::cuda::GpuMat input;
		input.upload(frame, stream);
		cv::cuda::GpuMat output;
		auto filter = cv::cuda::createGaussianFilter(input.type(), output.type(), cv::Size(parameters.Xsize, parameters.Ysize), parameters.x, parameters.y);
		filter->apply(input, output, stream);
		frame = cv::Mat(output);
	}
	clock_t stop = clock();
	clock_t time = stop - start;
	double result = time / (double)CLOCKS_PER_SEC;
}

bool GausianBlur::CheckParams()
{
	if(parameters.Xsize%2==0 || parameters.Ysize%2==0)
		return false;
	return true;
}

void GausianBlur::Print(std::ostream& out) const
{
	out << "#GaussianBlur#" << "#Parameters#" << "#XParam#" << parameters.x << "#X" << "#YParam#" << parameters.y << "#Y" << "#XSize#" << parameters.Xsize << "#X" << "#YSize#" << parameters.Ysize << "#Y" << "#P" << "#G";
}

void GausianBlur::Deserialize(std::vector<std::string>& strngs)
{
	for (size_t i = 0; i < strngs.size(); i++)
	{
		if (strngs[i] == "XParam")
		{
			parameters.x = std::stof(strngs[i + 1]);
			continue;
		}
		if (strngs[i] == "YParam")
		{
			parameters.y = std::stof(strngs[i + 1]);
			continue;
		}
		if (strngs[i] == "XSize")
		{
			parameters.Xsize = std::stoi(strngs[i + 1]);
			continue;
		}
		if (strngs[i] == "YSize")
		{
			parameters.Ysize = std::stoi(strngs[i + 1]);
			continue;
		}
	}
}

void GausianBlur::Deserialize(std::string value)
{
	auto strngs = MediaManager::getValuesFromString(value);
	Deserialize(strngs);
}

GausianBlurParam GausianBlur::getParams() const
{
	return parameters;
}
