#include "AudioRecognition.h"

AudioRecognition::FrameTypes AudioRecognition::RrecognizeFrameType(QAudioFormat format)
{
	int size = format.sampleSize();
	auto sample = format.sampleType();
	switch (sample)
	{
	case QAudioFormat::SignedInt:
		if (size == 8)
		{
			return AudioRecognition::FrameTypes::S8S;
		}
		else if (size == 16)
		{
			return AudioRecognition::FrameTypes::S16S;
		}
		else
		{
			return AudioRecognition::FrameTypes::SOther;
		}
		break;
	case QAudioFormat::UnSignedInt:
		if (size == 8)
		{
			return AudioRecognition::FrameTypes::S8U;
		}
		else if (size == 16)
		{
			return AudioRecognition::FrameTypes::S16U;
		}
		else
		{
			return AudioRecognition::FrameTypes::UOther;
		}
		break;
	case QAudioFormat::Float:
		if (size == 32)
		{
			return AudioRecognition::FrameTypes::S32F;
		}
		else
			return	AudioRecognition::FrameTypes::FOther;
		break;
	default:
		return	AudioRecognition::FrameTypes::Other;
		break;
	}
	//return QAudioFormat::SampleType();
}
