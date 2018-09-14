#include "AudioAnalyser.h"
#include<valarray>
#pragma region AudioAnalyser
template<typename T>
inline std::vector<double> AudioAnalyser::LoadDataFromBuffer(AudioAnalyser & analyser, QAudioBuffer buffer)
{
	T *frames = buffer.data<T>();
	std::vector<double>convertedFrames;
	for (size_t i = 0; i < buffer.frameCount(); i++)
	{
		 auto convertedFrame = analyser.ConvertInput(frames[i].average());
		 convertedFrames.push_back(convertedFrame);
	}
//	delete frames;
	return convertedFrames;
}
std::valarray<std::complex<double>> AudioAnalyser::Calculate(AudioAnalyser * analyser)
{
	////auto vector = LoadData();
	//std::valarray<std::complex<double>> data(vector.data(), vector.size());
	//FastFourierTransform* fft = new FastFourierTransform();
	//fft->Execute(data);
	//delete fft;
	//return data;
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
double S8SAudioAnalyser::ConvertInput(QVariant data)
{
	return data.toDouble() / maxAmplitude;
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
double S16SAudioAnalyser::ConvertInput(QVariant data)
{
	return data.toDouble() / maxAmplitude;
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
double S16UAudioAnalyser::ConvertInput(QVariant data)
{
	return data.toDouble() / maxAmplitude;
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
double S8UAudioAnalyser::ConvertInput(QVariant data)
{
	return data.toDouble() / maxAmplitude;
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
double S32FAudioAnalyser::ConvertInput(QVariant)
{
	return 0.0;
}
#pragma endregion