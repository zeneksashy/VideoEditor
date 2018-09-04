#pragma once
#include"qaudiobuffer.h"
#include"FastFourierTransform.h"
#define MY_CLASSES  MYTYPE(float) MYTYPE(char) MYTYPE(short) MYTYPE(ushort)  MYTYPE(uchar)
template<int N> class PowerOfTwo
{
public: static const int Result = PowerOfTwo<N - 1>::Result * 2;
};

template<> class PowerOfTwo<0>
{
public: static const int Result = 1;
};
template<typename T>
class AudioAnalyser
{
public:
	AudioAnalyser(QAudioBuffer buffer,QAudioFormat format):format(format),buffer(buffer){}
	virtual bool LoadData()=0;
	virtual void Calculate()=0;
	virtual double ConvertInput(T)=0;
	virtual double ConvertInput()=0;
	void LoadData(AudioAnalyser&);
	//virtual ~AudioAnalyser();
protected:
	QAudioBuffer buffer;
	QAudioFormat format;
	static const int FFTLengthPowerOfTwo = 12;
	const int SpectrumLengthSamples = PowerOfTwo<FFTLengthPowerOfTwo>::Result;
private:
	QByteArray spectrumBuffer;

};
class S8SAudioAnalyser:public AudioAnalyser<char>
{
public:
	S8SAudioAnalyser(QAudioBuffer buffer, QAudioFormat format) :AudioAnalyser(buffer, format) {}
	~S8SAudioAnalyser();
	// Inherited via AudioAnalyser
	virtual bool LoadData() override;
	virtual void Calculate() override;

	// Inherited via AudioAnalyser
	virtual double ConvertInput(char) override;
	virtual double ConvertInput() override;
private:
	const char maxValue = 127;
	const unsigned char maxAmplitude = maxValue;
};
class S16SAudioAnalyser :public AudioAnalyser<short>
{
public:
	S16SAudioAnalyser(QAudioBuffer buffer, QAudioFormat format) :AudioAnalyser(buffer, format) {}
	~S16SAudioAnalyser();


	// Inherited via AudioAnalyser
	virtual bool LoadData() override;

	virtual void Calculate() override;

};
class S16UAudioAnalyser :public AudioAnalyser<ushort>
{
public:
	S16UAudioAnalyser(QAudioBuffer buffer, QAudioFormat format) :AudioAnalyser(buffer, format) {}
	~S16UAudioAnalyser();

	// Inherited via AudioAnalyser
	virtual bool LoadData() override;

	virtual void Calculate() override;

};
class S8UAudioAnalyser :public AudioAnalyser<uchar>
{
public:
	S8UAudioAnalyser(QAudioBuffer buffer, QAudioFormat format) :AudioAnalyser(buffer, format) {}
	~S8UAudioAnalyser();
	// Inherited via AudioAnalyser
	virtual bool LoadData() override;

	virtual void Calculate() override;

};
class S32FAudioAnalyser :public AudioAnalyser<float>
{
public:
	S32FAudioAnalyser(QAudioBuffer buffer, QAudioFormat format) :AudioAnalyser(buffer, format) {}
	~S32FAudioAnalyser();




	// Inherited via AudioAnalyser
	virtual bool LoadData() override;

	virtual void Calculate() override;

};


