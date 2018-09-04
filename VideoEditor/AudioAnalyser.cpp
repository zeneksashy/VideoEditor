#include "AudioAnalyser.h"

#pragma region AudioAnalyser

void AudioAnalyser::LoadData(AudioAnalyser& analyser)
{
	auto bufferlength = SpectrumLengthSamples * (format.sampleSize() / 8) * format.channelCount();
	auto  spectrumBuffer = QByteArray::fromRawData(buffer.constData<char>(), bufferlength);
	const char *ptr = spectrumBuffer.constData();
	for (size_t i = 0; i < SpectrumLengthSamples; i++)
	{
		const T pcmSample = *reinterpret_cast<const T*>(ptr);
		
	}
}
#pragma endregion
#pragma region S8SAnalyser

S8SAudioAnalyser::~S8SAudioAnalyser()
{
}

bool S8SAudioAnalyser::LoadData()
{
	return false;
}

void S8SAudioAnalyser::Calculate()
{
}
double S8SAudioAnalyser::ConvertInput(char data)
{
	return 0.0;
}
double S8SAudioAnalyser::ConvertInput()
{
	return 0.0;
}
#pragma endregion
#pragma region S16SAnalyser
bool S16SAudioAnalyser::LoadData()
{
	return false;
}

void S16SAudioAnalyser::Calculate()
{
}
#pragma endregion
#pragma region S16UAudioAnalyser
bool S16UAudioAnalyser::LoadData()
{
	return false;
}

void S16UAudioAnalyser::Calculate()
{
}
#pragma endregion
#pragma region S8UAudioAnalyser

bool S8UAudioAnalyser::LoadData()
{
	return false;
}

void S8UAudioAnalyser::Calculate()
{
}
#pragma endregion
#pragma region S32FAudioAnalyser

bool S32FAudioAnalyser::LoadData()
{
	return false;
}

void S32FAudioAnalyser::Calculate()
{
}
#pragma endregion