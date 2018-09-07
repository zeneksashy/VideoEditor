#pragma once
#include"qaudiobuffer.h"
#include<vector>
#include<complex>
#include"FastFourierTransform.h"
#include<QVariant>
#include<memory>
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
	AudioAnalyser(QAudioBuffer buffer,QAudioFormat format):format(format),buffer(buffer){}
	virtual ComplexVector LoadData()=0;
	virtual std::valarray<std::complex<double>> Calculate()=0;
	virtual double ConvertInput(QVariant)=0;
protected:
	QAudioBuffer buffer;
	QAudioFormat format;
	std::valarray<std::complex<double>> Calculate(AudioAnalyser&);
	template <typename T>
	ComplexVector LoadData(AudioAnalyser&);
	static const int FFTLengthPowerOfTwo = 12;
	const int SpectrumLengthSamples = PowerOfTwo<FFTLengthPowerOfTwo>::Result;
private:
	QByteArray spectrumBuffer;

};
class S8SAudioAnalyser:public AudioAnalyser
{
public:
	S8SAudioAnalyser(QAudioBuffer buffer, QAudioFormat format) :AudioAnalyser(buffer, format) {}
	// Inherited via AudioAnalyser
	virtual ComplexVector LoadData() override;
	virtual std::valarray<std::complex<double>> Calculate() override;

	// Inherited via AudioAnalyser
	virtual double ConvertInput(QVariant) override;
	//virtual double ConvertInput() override;
private:
	const char maxValue = 127;
	const unsigned char maxAmplitude = maxValue;
};
class S16SAudioAnalyser :public AudioAnalyser
{
public:
	S16SAudioAnalyser(QAudioBuffer buffer, QAudioFormat format) :AudioAnalyser(buffer, format) {}
	// Inherited via AudioAnalyser

	virtual ComplexVector LoadData() override;

	virtual std::valarray<std::complex<double>> Calculate() override;

	virtual double ConvertInput(QVariant) override;
private:
	const short maxValue = 32767;
	const unsigned short maxAmplitude = 32768;

	// Inherited via AudioAnalyser
	
};
class S16UAudioAnalyser :public AudioAnalyser
{
public:
	S16UAudioAnalyser(QAudioBuffer buffer, QAudioFormat format) :AudioAnalyser(buffer, format) {}

	// Inherited via AudioAnalyser
	virtual ComplexVector LoadData() override;

	virtual std::valarray<std::complex<double>> Calculate() override;
private:
	const ushort maxValue = 65535;
	const unsigned short maxAmplitude = maxValue;

	// Inherited via AudioAnalyser
	virtual double ConvertInput(QVariant) override;
};
class S8UAudioAnalyser :public AudioAnalyser
{
public:
	S8UAudioAnalyser(QAudioBuffer buffer, QAudioFormat format) :AudioAnalyser(buffer, format) {}
	// Inherited via AudioAnalyser
	virtual ComplexVector LoadData() override;

	virtual std::valarray<std::complex<double>> Calculate() override;
private:
	const uchar maxValue = 255;
	const unsigned char maxAmplitude = maxValue;

	// Inherited via AudioAnalyser
	virtual double ConvertInput(QVariant) override;
};
//dont use
class S32FAudioAnalyser :public AudioAnalyser
{
public:
	S32FAudioAnalyser(QAudioBuffer buffer, QAudioFormat format) :AudioAnalyser(buffer, format) {}
	// Inherited via AudioAnalyser
	virtual ComplexVector LoadData() override;

	virtual std::valarray<std::complex<double>> Calculate() override;
private:
	const char maxValue = 3321321 ;
	const unsigned char maxAmplitude = maxValue;

	// Inherited via AudioAnalyser
	virtual double ConvertInput(QVariant) override;
};


