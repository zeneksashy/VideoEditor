#pragma once
#include<complex>
#include<valarray>
#include<qaudiobuffer.h>
#include"AudioRecognition.h"

class FastFourierTransform
{
public:
	FastFourierTransform(QAudioBuffer);
	void Execute(std::valarray<std::complex<double>> &x);
	~FastFourierTransform();
private:
	QAudioBuffer buffer;
	AudioRecognition::FrameTypes frame;
};

