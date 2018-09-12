#pragma once
#include<complex>
#include<valarray>
#include<vector>


class FastFourierTransform
{
public:

	void Execute(std::valarray<std::complex<double>> &x);
	std::vector<double> CalculateAmplitude(std::valarray<std::complex<double>> &x);
};

