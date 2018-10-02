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
	return data;
}
//23 seconds size 3x9 y = 1 x = 4.5 on cpu
//3.2 second size 3x9 y =1 x =4.5 on gpu
void GausianBlur::Calculate(cv::Mat& frame)
{
	clock_t start = clock();
	if (CheckParams())
	{
		cv::cuda::Stream stream;
		//cv::cuda::HostMem locked(frame);
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

void GausianBlur::Deserialize(std::string path)
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

GausianBlurParam GausianBlur::getParams() const
{
	return parameters;
}
