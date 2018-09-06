#include "AudioRecognition.h"

AudioAnalyser* AudioRecognition::RrecognizeFrameType(QAudioBuffer buffer,QAudioFormat format)
{
	int size = format.sampleSize();
	auto sample = format.sampleType();
	switch (sample)
	{
	case QAudioFormat::SignedInt:
		if (size == 8)
		{
			return new S8SAudioAnalyser(buffer, format);
		}
		else if (size == 16)
		{
			return new S16SAudioAnalyser(buffer, format);
		}
		else
		{
			//return AudioRecognition::FrameTypes::SOther;
		}
		break;
	case QAudioFormat::UnSignedInt:
		if (size == 8)
		{
			return new S8UAudioAnalyser(buffer, format);
		}
		else if (size == 16)
		{
			return new S16UAudioAnalyser(buffer, format);
		}
		else
		{
			//return AudioRecognition::FrameTypes::UOther;
		}
		break;
	case QAudioFormat::Float:
		if (size == 32)
		{
			return new S32FAudioAnalyser(buffer, format);
		}
		else
			//return	AudioRecognition::FrameTypes::FOther;
		break;
	default:
		//return	AudioRecognition::FrameTypes::Other;
		break;
	}
	return nullptr;
	//return QAudioFormat::SampleType();
}
