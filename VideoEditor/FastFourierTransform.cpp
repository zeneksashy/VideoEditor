#include "FastFourierTransform.h"


//add adudio recognisation and maybe do all stuff with converting audiobuffer
//FastFourierTransform::FastFourierTransform(QAudioBuffer buffer)
//{
////	this->buffer = buffer;
//	//AudioRecognition recognize;
//	//frame = recognize.RrecognizeFrameType(buffer.format);
//}
void FastFourierTransform::Execute(std::valarray<std::complex<double>> &x)
{
	// DFT
	unsigned int N = x.size(), k = N, n;
	double thetaT = 3.14159265358979323846264338328L / N;
	std::complex<double> phiT = std::complex<double>(cos(thetaT), -sin(thetaT)), T;
	while (k > 1)
	{
		n = k;
		k >>= 1;
		phiT = phiT * phiT;
		T = 1.0L;
		for (unsigned int l = 0; l < k; l++)
		{
			for (unsigned int a = l; a < N; a += n)
			{
				unsigned int b = a + k;
				std::complex<double> t = x[a] - x[b];
				x[a] += x[b];
				x[b] = t * T;
			}
			T *= phiT;
		}
	}
	// Decimate
	unsigned int m = (unsigned int)log2(N);
	for (unsigned int a = 0; a < N; a++)
	{
		unsigned int b = a;
		// Reverse bits
		b = (((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1));
		b = (((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2));
		b = (((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4));
		b = (((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8));
		b = ((b >> 16) | (b << 16)) >> (32 - m);
		if (b > a)
		{
			std::complex<double> t = x[a];
			x[a] = x[b];
			x[b] = t;
		}
	}
}

const qint16  PCMS16MaxValue = 32767;
const quint16 PCMS16MaxAmplitude = 32768; // because minimum is -32768
qreal pcmToReal(qint16 pcm)
{
	return qreal(pcm) / PCMS16MaxAmplitude;
}
//QVector<float> m_window;
//QVector<float> m_input;
//QVector<float> m_output;
//void FastFourierTransform::LoadData()
//{
//	int bytesPerSample=2;
//	
//	const char *ptr = spectrumBuffer.constData();
//	 auto numSamples = SpectrumLengthSamples;
//	for (int i = 0; i < numSamples; ++i) {
//		const signed short pcmSample = *reinterpret_cast<const qint16*>(ptr);
//		// Scale down to range [-1.0, 1.0]
//		const double realSample = pcmToReal(pcmSample);
//		//const double windowedSample = realSample * m_window[i];
//	//	m_input[i] = windowedSample;
//		ptr += bytesPerSample;
//	}
////	auto data = buffer.data<double>();
//	QAudioBuffer::S16U *frames = buffer.data<QAudioBuffer::S16U>();
//	for (size_t i = 0; i < buffer.frameCount(); i++)
//	{
//		auto x = frames->average();
//	}
//	switch (frame)
//	{
//	case AudioRecognition::S8S:
//
//		break;
//	case AudioRecognition::S16S:
//		
//		break;
//	case AudioRecognition::S8U:
//		break;
//	case AudioRecognition::S16U:
//		break;
//	case AudioRecognition::S32F:
//		break;
//	case AudioRecognition::SOther:
//		break;
//	case AudioRecognition::UOther:
//		break;
//	case AudioRecognition::FOther:
//		break;
//	case AudioRecognition::Other:
//		break;
//	default:
//		break;
//	}
//}
