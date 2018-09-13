#include "FastFourierTransform.h"
#include<qmath.h>


void FastFourierTransform::Execute(std::valarray<std::complex<double>> &x)
{
	// DFT
	unsigned int N = x.size(), k = N, n;
	double thetaT = 3.14159265358979323846264338328L / N;
	std::complex<double> phiT = std::complex<double>(cos(thetaT), -sin(thetaT)), T;
	try
	{
		while (k > 1)
		{
			n = k;
			k >>= 1;
			phiT = phiT * phiT;
			T = 1.0L;
			for (unsigned int l = 0; l < k; l++)
			{
				for (unsigned int a = l; a < N; a += n)
				{
					unsigned int b = a + k;
					std::complex<double> t = x[a] - x[b];
					x[a] += x[b];
					x[b] = t * T;
				}
				T *= phiT;
			}
		}
	}
	catch (const std::exception& e)
	{
		e.what();
	}
	
	// Decimate
	unsigned int m = (unsigned int)log2(N);
	for (unsigned int a = 0; a < N; a++)
	{
		unsigned int b = a;
		// Reverse bits
		b = (((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1));
		b = (((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2));
		b = (((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4));
		b = (((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8));
		b = ((b >> 16) | (b << 16)) >> (32 - m);
		if (b > a)
		{
			std::complex<double> t = x[a];
			x[a] = x[b];
			x[b] = t;
		}
	}
}

std::vector<double> FastFourierTransform::CalculatedBLevel(std::vector<double> frames)
{
	std::vector<double> dBLevels;

	for (size_t i = 0; i < frames.size(); i++)
	{
		double temp = 0;
		if (frames[i] < 0)
		{
			auto unsignedFrame = frames[i] * -1;
			temp = std::log10(unsignedFrame);
		}
		else if (frames[i] > 0)
		{
			temp = std::log10(frames[i]);
		}
		dBLevels.push_back(temp * 20);
	}
	return dBLevels;
}

void FastFourierTransform::Normalize(std::vector<double>& samples)
{
	auto vmax = std::max_element(samples.begin(), samples.end());
	double max = *vmax;
	auto vmin = std::min_element(samples.begin(), samples.end());
	double min = *vmin;
	for (size_t i = 0; i < samples.size(); i++)
	{
		auto temp = min * -1;
		samples[i] += temp;
	}
	for (size_t i = 0; i < samples.size(); i++)
	{
		samples[i] /= (max - min);
	}
}

std::vector<double> FastFourierTransform::RootMeanSquare(std::vector<double>& samples, int sampleSize)
{
	std::vector<double> outputSamples;
	auto size = samples.size() / sampleSize;
	int k = 0;
	for (size_t i = 1; i <= size; i++)
	{
		double temp = 0;
		for (size_t j = k; j < sampleSize * i; j++)
		{
			temp += samples[j] * samples[j];
		}
		temp /= sampleSize;
		outputSamples.push_back(std::sqrt(temp));
		k += sampleSize;
	}
	return outputSamples;
}
