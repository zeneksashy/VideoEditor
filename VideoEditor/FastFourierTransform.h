#pragma once
#include<complex>
#include<valarray>
#include<vector>
#include <ctime>
#include<qmath.h>
class FastFourierTransform
{
public:

	void Execute(std::valarray<std::complex<double>> &x);
	std::vector<double> CalculatedBLevel(std::vector<double> frames);
	 void Normalize(std::vector<double> &samples);
	 std::vector<double> RootMeanSquare(std::vector<double> &samples,int sampleSize);
	 std::vector<double> RootMeanSquare(std::vector<double> &samples, double sampleSize);
};
