#include "AudioAnalyser.h"
#include<valarray>
#pragma region AudioAnalyser

template<typename T>
inline std::vector<std::complex<double>> AudioAnalyser<T>::LoadData(AudioAnalyser & analyser)
{
	const int bytesPerSample = format.sampleSize() * format.channelCount() / 8;// not sure if it depends on format or not
	auto bufferlength = SpectrumLengthSamples * (format.sampleSize() / 8) * format.channelCount();
	auto  spectrumBuffer = QByteArray::fromRawData(buffer.constData<char>(), bufferlength);
	const char *ptr = spectrumBuffer.constData();
	std::vector<std::complex<double>> complex;
	for (size_t i = 0; i < buffer.frameCount(); i++)
	{
		const T pcmSample = *reinterpret_cast<const T*>(ptr);
		const double input = analyser.ConvertInput(pcmSample);
		std::complex<double> temp(input);
		complex.push_back(temp);
		ptr += bytesPerSample;
	}
	return complex;
}
#pragma endregion
#pragma region S8SAnalyser

S8SAudioAnalyser::~S8SAudioAnalyser()
{
}

ComplexVector S8SAudioAnalyser::LoadData()
{
	auto data = AudioAnalyser::LoadData(*this);
	return data;
}

void S8SAudioAnalyser::Calculate()
{
}
double S8SAudioAnalyser::ConvertInput(char data)
{
	return double(data) / maxAmplitude;
}
//double S8SAudioAnalyser::ConvertInput()
//{
//	return 0.0;
//}
#pragma endregion
#pragma region S16SAnalyser
ComplexVector S16SAudioAnalyser::LoadData()
{
	auto data = AudioAnalyser::LoadData(*this);
	return data;
}

void S16SAudioAnalyser::Calculate()
{
}
double S16SAudioAnalyser::ConvertInput(short data)
{
	return double(data) / maxAmplitude;
}
#pragma endregion
#pragma region S16UAudioAnalyser
ComplexVector S16UAudioAnalyser::LoadData()
{
	auto data = AudioAnalyser::LoadData(*this);
	return data;
}

void S16UAudioAnalyser::Calculate()
{
}
double S16UAudioAnalyser::ConvertInput(ushort data)
{
	return double(data) / maxAmplitude;
}
#pragma endregion
#pragma region S8UAudioAnalyser

ComplexVector S8UAudioAnalyser::LoadData()
{
	auto data = AudioAnalyser::LoadData(*this);
	return data;
}

void S8UAudioAnalyser::Calculate()
{
}
double S8UAudioAnalyser::ConvertInput(uchar data)
{
	return double(data) / maxAmplitude;
}
#pragma endregion
#pragma region S32FAudioAnalyser

ComplexVector S32FAudioAnalyser::LoadData()
{
	auto data = AudioAnalyser::LoadData(*this);
	return data;
}

void S32FAudioAnalyser::Calculate()
{
}
double S32FAudioAnalyser::ConvertInput(float)
{
	return 0.0;
}
#pragma endregion