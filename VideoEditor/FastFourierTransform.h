#pragma once
#include<complex>
#include<valarray>
#include<qaudiobuffer.h>
#include"AudioRecognition.h"


class FastFourierTransform
{
public:
	FastFourierTransform();
	void Execute(std::valarray<std::complex<double>> &x);
	void LoadData();

private:
	QAudioBuffer buffer;
	QAudioFormat format;
	AudioRecognition::FrameTypes frame;
};

