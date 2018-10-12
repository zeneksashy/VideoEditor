#pragma once
#include <QtTest/QtTest>
#include<Player.h>
#include <iostream>
#include "GausianBlur.h"
#include "AudioRecognition.h"
#include <qaudioformat.h>
#include"AudioAnalyser.h"
#include <QtWidgets/QApplication>
#include<QtQml/qqmlapplicationengine.h>
#include <QObject>
#include "MedianBlur.h"

class SerializationTest :QObject
{
	Q_OBJECT
public:
	bool PlayerTest();
	bool SettingsSerialization();
	bool EffectsSerialization();
	bool SettingsDeserialization();
	bool EffectsDeserialization();
	bool EffectContainerSerialization();
	bool MediaManagerDeserialization();

private:
	std::string gaussianExpected = "#GaussianBlur##Parameters##XParam#3.5#X#YParam#4.2#Y#XSize#5#X#YSize#11#Y#P#G";
	std::string settingsExpected = "#Project##Settings##Video##Width#1#W#Height#2#H#FrameRate# 3.5#F#V#S#P";
	std::string effectContainerExpected = "#GaussianBlur##Parameters##XParam#3.5#X#YParam#4.2#Y#XSize#5#X#YSize#11#Y#P#G#MedianBlur##Kernel#5#K#M";
};
class FastFourierTransformTest :public QObject
{
	Q_OBJECT
public:
	bool CalculatedBLevel()
	{
		int multipler = 100;
		double amp = 0.44;
		std::vector<double> data = { amp };
		FastFourierTransform ft;
		auto act = ft.CalculatedBLevel(data);
		int actual = act[0] * multipler;
		int expected = -7.13*multipler;
		if (actual == expected)
			return true;
		return false;
	}
	bool NormalizeSamples()
	{
		std::vector<double> actual = { -4, 0, 5, 6, 9 };
		std::vector<double> expected = { 0,0.3076923076923077,0.6923076923076923,0.7692307692307692,1 };
		FastFourierTransform ft;
		ft.Normalize(actual);
		for (size_t i = 0; i < actual.size(); i++)
		{
			if(actual[i] * multipler!= expected[i] * multipler);
				return false;
		}
		return true;
	}
	bool RootMeanSquare()
	{
		std::vector<double> tempData = { 5,3,2,1,-9,-2 };
		int expected = 4.54606056566 * multipler;
		FastFourierTransform cut;
		auto act = cut.RootMeanSquare(tempData, 6);
		if (act.size() != 1)
			return false;
		int actual = act[0] * multipler;
		if (actual == expected)
			return true;
		return false;
	}

private:
	const int multipler = 100000;
};
class GausianBlurTest :QObject
{
	Q_OBJECT
public:
bool GausianBlurParamsNonOddNumbers()
{
	GausianBlur b;
	GausianBlurParam params;
	params.Create(3, 9, 5, 3);
	b.Initialize(params);
	b.CheckParams();
	if (b.CheckParams())
		return true;
	return false;
}
};
class AudioRecognitionTest : public QObject
{
	Q_OBJECT
public:
	bool AudioFormatRegonitionTest_SampleSize8()
	{
		QAudioBuffer buffer;
		QAudioFormat format;
		format.setSampleSize(8);
		format.setSampleType(QAudioFormat::SampleType::UnSignedInt);
		AudioRecognition rec;
		auto actual = rec.RrecognizeFrameType(format);
		S8UAudioAnalyser* result = dynamic_cast<S8UAudioAnalyser*>(actual);
		if (result != 0)
		{
			delete result;
			delete actual;
			return true;
		}
		else
		{
			delete result;
			delete actual;
			return false;
		}
		delete result;
		delete actual;
	}
	bool AudioFormatRegonitionTest_SampleSize32()
	{
		QAudioBuffer buffer;
		QAudioFormat format;
		format.setSampleSize(32);
		format.setSampleType(QAudioFormat::SampleType::Float);
		AudioRecognition rec;
		auto actual = rec.RrecognizeFrameType(format);
		S32FAudioAnalyser* result = dynamic_cast<S32FAudioAnalyser*>(actual);
		if (result != 0)
		{
			delete result;
			delete actual;
			return true;
		}
		else
		{
			delete result;
			delete actual;
			return false;
		}

	}
};
class AudioAnalyserTest :public QObject
{
	Q_OBJECT

public:
	//gives 2557 and it should return 0.0780334473
	bool ConvertDataS16S()
	{
		int multipler = 100000;
		auto analyser = new S16SAudioAnalyser();
		double exp = 0.0780334473;
		auto act = analyser->ConvertInput(2557);
		int expected = exp * multipler; // simple work around 
		int actual = act * multipler;	// of rounding errors
		delete analyser;
		QTRY_COMPARE(actual, expected);
		if (actual == expected)
			return true;
		return false;
	}

private:
	QAudioBuffer buffer;
	QAudioFormat format;
};