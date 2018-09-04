#pragma once

#include <QObject>
#include<qaudiobuffer.h>
class AudioRecognition : public QObject
{
	Q_OBJECT

public:
	enum FrameTypes
	{
		S8S, S16S, S8U, S16U, S32F, SOther,UOther,FOther,Other
	};

	 AudioRecognition::FrameTypes RrecognizeFrameType(QAudioFormat);
	/*AudioRecognition(QObject *parent = nullptr);
	~AudioRecognition();*/
private:
	//QAudioFormat::SampleType getSampleType();
};
