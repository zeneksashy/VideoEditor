
#include<qaudioformat.h>
#include<qobject.h>
#include<AudioRecognition.h>
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

QTEST_MAIN(AudioRecognitionTest)

#include "tester.moc"