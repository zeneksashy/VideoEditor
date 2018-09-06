#pragma once

#include <QObject>
#include"AudioAnalyser.h"
class AudioAnalyser;
class AudioRecognition : public QObject
{
	Q_OBJECT
public:

	AudioAnalyser* RrecognizeFrameType(QAudioBuffer, QAudioFormat);

};
