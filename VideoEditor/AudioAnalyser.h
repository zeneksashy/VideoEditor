#pragma once
#include"qaudiobuffer.h"
#include<vector>
#include<complex>
#include"FastFourierTransform.h"
#include<QVariant>

//#define _ITERATOR_DEBUG_LEVEL 1

#define ComplexVector std::vector<std::complex<double>>
template<int N> class PowerOfTwo
{
public: static const int Result = PowerOfTwo<N - 1>::Result * 2;
};
template<> class PowerOfTwo<0>
{
public: static const int Result = 1;
};

class AudioAnalyser
{
public:
	AudioAnalyser() {}
	virtual std::vector<double> LoadDataFromBuffer(QAudioBuffer)=0;
	virtual std::valarray<std::complex<double>> Calculate()=0;
	virtual double ConvertInput(double)=0;
protected:
	std::valarray<std::complex<double>> Calculate(AudioAnalyser*);
	template <typename T>
	std::vector<double> LoadDataFromBuffer(AudioAnalyser&, QAudioBuffer);
};
class S8SAudioAnalyser:public AudioAnalyser
{
public:
	S8SAudioAnalyser() :AudioAnalyser() {}
	// Inherited via AudioAnalyser
	virtual std::vector<double> LoadDataFromBuffer(QAudioBuffer) override;
	virtual std::valarray<std::complex<double>> Calculate() override;

	// Inherited via AudioAnalyser
	virtual double ConvertInput(double) override;
	//virtual double ConvertInput() override;
private:
	const char maxValue = 127;
	const unsigned char maxAmplitude = maxValue;
};
class S16SAudioAnalyser :public AudioAnalyser
{
public:
	S16SAudioAnalyser() :AudioAnalyser() {}
	// Inherited via AudioAnalyser

	virtual std::vector<double> LoadDataFromBuffer(QAudioBuffer) override;

	virtual std::valarray<std::complex<double>> Calculate() override;

	virtual double ConvertInput(double) override;
private:
	const short maxValue = 32767;
	const unsigned short maxAmplitude = 32768;

	// Inherited via AudioAnalyser
	
};
class S16UAudioAnalyser :public AudioAnalyser
{
public:
	S16UAudioAnalyser() :AudioAnalyser() {}

	// Inherited via AudioAnalyser
	virtual std::vector<double> LoadDataFromBuffer(QAudioBuffer) override;

	virtual std::valarray<std::complex<double>> Calculate() override;
private:
	const ushort maxValue = 65535;
	const unsigned short maxAmplitude = maxValue;

	// Inherited via AudioAnalyser
	virtual double ConvertInput(double) override;
};
class S8UAudioAnalyser :public AudioAnalyser
{
public:
	S8UAudioAnalyser() :AudioAnalyser() {}
	// Inherited via AudioAnalyser
	virtual std::vector<double> LoadDataFromBuffer(QAudioBuffer) override;

	virtual std::valarray<std::complex<double>> Calculate() override;
private:
	const uchar maxValue = 255;
	const unsigned char maxAmplitude = maxValue;

	// Inherited via AudioAnalyser
	virtual double ConvertInput(double) override;
};
//dont use
class S32FAudioAnalyser :public AudioAnalyser
{
public:
	S32FAudioAnalyser() :AudioAnalyser() {}
	// Inherited via AudioAnalyser
	virtual std::vector<double> LoadDataFromBuffer(QAudioBuffer) override;

	virtual std::valarray<std::complex<double>> Calculate() override;
private:
	const char maxValue = 3321321 ;
	const unsigned char maxAmplitude = maxValue;

	// Inherited via AudioAnalyser
	virtual double ConvertInput(double) override;
};


