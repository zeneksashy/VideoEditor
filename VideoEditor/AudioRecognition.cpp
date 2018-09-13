#include "AudioRecognition.h"

AudioAnalyser* AudioRecognition::RrecognizeFrameType(QAudioFormat format)
{
	int size = format.sampleSize();
	auto sample = format.sampleType();
	switch (sample)
	{
	case QAudioFormat::SignedInt:
		if (size == 8)
		{
			return new S8SAudioAnalyser();
		}
		else if (size == 16)
		{
			return new S16SAudioAnalyser();
		}
		else
		{
			//return AudioRecognition::FrameTypes::SOther;
		}
		break;
	case QAudioFormat::UnSignedInt:
		if (size == 8)
		{
			return new S8UAudioAnalyser();
		}
		else if (size == 16)
		{
			return new S16UAudioAnalyser();
		}
		else
		{
			//return AudioRecognition::FrameTypes::UOther;
		}
		break;
	case QAudioFormat::Float:
		if (size == 32)
		{
			return new S32FAudioAnalyser();
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
