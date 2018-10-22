#include "AudioAnalyser.h"
#include<valarray>
#pragma region AudioAnalyser
template<typename T>
inline std::vector<double> AudioAnalyser::LoadDataFromBuffer(AudioAnalyser & analyser, QAudioBuffer buffer)
{
	//push back slows it for almost a second
	T *frames = buffer.data<T>();
	std::vector<double>convertedFrames(buffer.frameCount());
	for (size_t i = 0; i < buffer.frameCount(); i++)
	{
		 convertedFrames[i] = analyser.ConvertInput((double)frames[i].average());
	}
	return convertedFrames;
}
std::valarray<std::complex<double>> AudioAnalyser::Calculate(AudioAnalyser * analyser)
{
	std::valarray<std::complex<double>> vec;
	return vec;
}
#pragma endregion
#pragma region S8SAnalyser


std::vector<double> S8SAudioAnalyser::LoadDataFromBuffer(QAudioBuffer buffer)
{
	return AudioAnalyser::LoadDataFromBuffer<QAudioBuffer::S8S>(*this,buffer);
}

std::valarray<std::complex<double>> S8SAudioAnalyser::Calculate()
{
	return AudioAnalyser::Calculate(this);
}
double S8SAudioAnalyser::ConvertInput(double data)
{
	return data / maxAmplitude;
}

#pragma endregion
#pragma region S16SAnalyser
std::vector<double> S16SAudioAnalyser::LoadDataFromBuffer(QAudioBuffer buffer)
{
	return AudioAnalyser::LoadDataFromBuffer<QAudioBuffer::S16S>(*this, buffer);
}

std::valarray<std::complex<double>> S16SAudioAnalyser::Calculate()
{
	return AudioAnalyser::Calculate(this);
}
double S16SAudioAnalyser::ConvertInput(double data)
{
	return data / maxAmplitude;
}
#pragma endregion
#pragma region S16UAudioAnalyser
std::vector<double> S16UAudioAnalyser::LoadDataFromBuffer(QAudioBuffer buffer)
{
	return AudioAnalyser::LoadDataFromBuffer<QAudioBuffer::S16U>(*this, buffer);
}

std::valarray<std::complex<double>> S16UAudioAnalyser::Calculate()
{
	return AudioAnalyser::Calculate(this);
}
double S16UAudioAnalyser::ConvertInput(double data)
{
	return data / maxAmplitude;
}
#pragma endregion
#pragma region S8UAudioAnalyser

std::vector<double> S8UAudioAnalyser::LoadDataFromBuffer(QAudioBuffer buffer)
{
	return AudioAnalyser::LoadDataFromBuffer<QAudioBuffer::S8U>(*this, buffer);

}

std::valarray<std::complex<double>> S8UAudioAnalyser::Calculate()
{
	return AudioAnalyser::Calculate(this);
}
double S8UAudioAnalyser::ConvertInput(double data)
{
	return data / maxAmplitude;
}
#pragma endregion
#pragma region S32FAudioAnalyser

std::vector<double> S32FAudioAnalyser::LoadDataFromBuffer(QAudioBuffer buffer)
{
	return AudioAnalyser::LoadDataFromBuffer<QAudioBuffer::S32F>(*this, buffer);
}

std::valarray<std::complex<double>> S32FAudioAnalyser::Calculate()
{
	return AudioAnalyser::Calculate(this);
}
double S32FAudioAnalyser::ConvertInput(double)
{
	return 0.0;
}
#pragma endregion