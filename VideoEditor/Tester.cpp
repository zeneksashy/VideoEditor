
#include<qaudioformat.h>
#include<qobject.h>
#include<AudioRecognition.h>
#include"AudioAnalyser.h"
#include <QtTest/QtTest>
class AudioRecognitionTest : public QObject
{
	Q_OBJECT
private slots:
	void AudioFormatRegonitionTest_SampleSize8()
	{
		QAudioFormat format;
		format.setSampleSize(8);
		format.setSampleType(QAudioFormat::SampleType::UnSignedInt);
		AudioRecognition rec;
		auto actual = rec.RrecognizeFrameType(format);
		auto expected = AudioRecognition::S8U;
		QTRY_COMPARE(actual, expected);
	}
	void AudioFormatRegonitionTest_SampleSize32()
	{
		QAudioFormat format;
		format.setSampleSize(32);
		format.setSampleType(QAudioFormat::SampleType::Float);
		AudioRecognition rec;
		auto actual = rec.RrecognizeFrameType(format);
		auto expected = AudioRecognition::S32F;
		QTRY_COMPARE(actual, expected);
	}
	void AudioFormatRegonitionTest_SampleNotDefault()
	{
		QAudioFormat format;
		format.setSampleSize(164);
		format.setSampleType(QAudioFormat::SampleType::Float);
		AudioRecognition rec;
		auto actual = rec.RrecognizeFrameType(format);
		auto expected = AudioRecognition::Other;
		QTRY_COMPARE(actual, expected);
	}

};
class AudioAnalyserTest:public QObject
{
	Q_OBJECT

private slots:
	//gives 2557 and it should return 0.0780334473
	void ConvertDataS16S()
	{
		int multipler = 100000;
		
		auto analyser = new S16SAudioAnalyser(buffer, format);
		double exp = 0.0780334473;
		auto act= analyser->ConvertInput(2557);
		int expected = exp * multipler; // simple work around 
		int actual = act * multipler;	// of rounding errors
		QTRY_COMPARE(actual, expected);
	}
	void LoadData_Empty()
	{
		auto analyser = new S16SAudioAnalyser(buffer, format);
		auto actual = analyser->LoadData();
		auto expected = ComplexVector();
		QTRY_COMPARE(actual.size(), expected.size());
	}
	void LoadData()
	{
		QByteArray data;
		format.setSampleSize(16);
		format.setChannelCount(2);
		format.setSampleType(QAudioFormat::SignedInt);
		auto buff = new QAudioBuffer(data, format, 0);
		auto analyser = new S16SAudioAnalyser(*buff, format);
		auto actual = analyser->LoadData();
		auto expected = ComplexVector();
		QTRY_COMPARE(actual.size(), expected.size());
	}
	void CalculateData()
	{

	}
private:
	QAudioBuffer buffer;
	QAudioFormat format;
};


//QTEST_MAIN(AudioAnalyserTest)

#include "tester.moc"
