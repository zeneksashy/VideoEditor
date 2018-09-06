#pragma once

#include <QObject>
#include<qaudiobuffer.h>
#include"AudioAnalyser.h"
class AudioRecognition : public QObject
{
	Q_OBJECT

public:
	enum FrameTypes
	{
		S8S, S16S, S8U, S16U, S32F, SOther,UOther,FOther,Other
	};

	AudioAnalyser* RrecognizeFrameType(QAudioBuffer,QAudioFormat);

private:
	//QAudioFormat::SampleType getSampleType();
};
