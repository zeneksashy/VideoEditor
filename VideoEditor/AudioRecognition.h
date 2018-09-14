#pragma once

//#include <QObject>
#include<qobject.h>
#include"AudioAnalyser.h"
class AudioAnalyser;
class AudioRecognition : public QObject
{
	Q_OBJECT
public:

	AudioAnalyser* RrecognizeFrameType(QAudioFormat);

};
