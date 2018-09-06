
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
		QAudioBuffer buffer;
		QAudioFormat format;
		format.setSampleSize(8);
		format.setSampleType(QAudioFormat::SampleType::UnSignedInt);
		AudioRecognition rec;
		auto actual = rec.RrecognizeFrameType(buffer,format);
		S8UAudioAnalyser* result = dynamic_cast<S8UAudioAnalyser*>(actual);
		 if (result != 0)
		 {
			 Q_ASSERT(true);
		 }
		 else
		 {
			 Q_ASSERT(false);
		 }
		 delete result;
		 delete actual;
	}
	void AudioFormatRegonitionTest_SampleSize32()
	{
		QAudioBuffer buffer;
		QAudioFormat format;
		format.setSampleSize(32);
		format.setSampleType(QAudioFormat::SampleType::Float);
		AudioRecognition rec;
		auto actual = rec.RrecognizeFrameType(buffer,format);
		S32FAudioAnalyser* result = dynamic_cast<S32FAudioAnalyser*>(actual);
		if (result != 0)
		{
			Q_ASSERT(true);
		}
		else
		{
			Q_ASSERT(false);
		}
		delete result;
		delete actual;
	}
	void AudioFormatRegonitionTest_SampleNotDefault()
	{
		QAudioBuffer buffer;
		QAudioFormat format;
		format.setSampleSize(164);
		format.setSampleType(QAudioFormat::SampleType::Float);
		AudioRecognition rec;
		auto actual = rec.RrecognizeFrameType(buffer,format);
		/*auto expected = AudioRecognition::Other;
		QTRY_COMPARE(actual, expected);*/
		//delete result;
		delete actual;
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
		delete analyser;
	}
	void LoadData_Empty()
	{
		auto analyser = new S16SAudioAnalyser(buffer, format);
		auto actual = analyser->LoadData();
		auto expected = ComplexVector();
		QTRY_COMPARE(actual.size(), expected.size());
		delete analyser;
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
		delete buff;
	}
	void CalculateData()
	{

	}
private:
	QAudioBuffer buffer;
	QAudioFormat format;
};


QTEST_MAIN(AudioAnalyserTest)

#include "tester.moc"
