#include "FastFourierTransform.h"
#include<qmath.h>


void FastFourierTransform::Execute(std::valarray<std::complex<double>> &x)
{
	// DFT
	unsigned int N = x.size(), k = N, n;
	double thetaT = 3.14159265358979323846264338328L / N;
	std::complex<double> phiT = std::complex<double>(cos(thetaT), -sin(thetaT)), T;
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

std::vector<double> FastFourierTransform::CalculateAmplitude(std::valarray<std::complex<double>>& x)
{
	std::vector<double> values;
	for (size_t i = 0; i < x.size(); i++)
	{
		auto imaginary = x[i].imag();
		auto real = x[i].real();
		const auto magnitude = std::sqrt(real*real + imaginary * imaginary);
		auto amplitude = 0.15 * qLn(magnitude);
		amplitude = qMax(qreal(0.0), amplitude);
		amplitude = qMin(qreal(1.0), amplitude);
		values.push_back(amplitude);
	}
	return values;
}
