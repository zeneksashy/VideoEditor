#include "AudioAnalyser.h"
#include<valarray>
#pragma region AudioAnalyser

template<typename T>
inline std::vector<std::complex<double>> AudioAnalyser::LoadData(AudioAnalyser & analyser)
{
	const int bytesPerSample = format.sampleSize() * format.channelCount() / 8;// not sure if it depends on format or not
	auto bufferlength = SpectrumLengthSamples * (format.sampleSize() / 8) * format.channelCount();
	auto  spectrumBuffer = QByteArray::fromRawData(buffer.constData<char>()+37376-34560, bufferlength);
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
std::valarray<std::complex<double>> AudioAnalyser::Calculate(AudioAnalyser * analyser)
{
	auto vector = LoadData();
	std::valarray<std::complex<double>> data(vector.data(), vector.size());
	FastFourierTransform* fft = new FastFourierTransform();
	fft->Execute(data);
	delete fft;
	return data;
}
#pragma endregion
#pragma region S8SAnalyser


ComplexVector S8SAudioAnalyser::LoadData()
{
	auto data = AudioAnalyser::LoadData<char>(*this);
	return data;
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
ComplexVector S16SAudioAnalyser::LoadData()
{
	auto data = AudioAnalyser::LoadData<short>(*this);
	return data;
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
ComplexVector S16UAudioAnalyser::LoadData()
{
	auto data = AudioAnalyser::LoadData<ushort>(*this);
	return data;
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

ComplexVector S8UAudioAnalyser::LoadData()
{
	auto data = AudioAnalyser::LoadData<uchar>(*this);
	return data;
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

ComplexVector S32FAudioAnalyser::LoadData()
{
	auto data = AudioAnalyser::LoadData<float>(*this);
	return data;
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


