
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
		auto actual = rec.RrecognizeFrameType(format);
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
		auto actual = rec.RrecognizeFrameType(format);
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
		auto actual = rec.RrecognizeFrameType(format);
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
		auto analyser = new S16SAudioAnalyser();
		double exp = 0.0780334473;
		auto act= analyser->ConvertInput(2557);
		int expected = exp * multipler; // simple work around 
		int actual = act * multipler;	// of rounding errors
		QTRY_COMPARE(actual, expected);
		delete analyser;
	}
	void LoadData_Empty()
	{
		auto analyser = new S16SAudioAnalyser();
		auto actual = analyser->LoadDataFromBuffer(buffer);
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
		auto analyser = new S16SAudioAnalyser();
		auto actual = analyser->LoadDataFromBuffer(buffer);
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
class FastFourierTransformTest :public QObject
{
	Q_OBJECT
private slots:
	void ExcuteTransform()
	{
		std::complex<double> test[] = { 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 };
		std::complex<double> expected[] = { 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 };
		std::valarray<std::complex<double>> data(test, 8);
		FastFourierTransform ft;
		ft.Execute(data);
	}
	void CalculatedBLevel()
	{
		int multipler = 100;
		double amp = 0.44;
		std::vector<double> data = { amp };
		FastFourierTransform ft;
		auto act = ft.CalculatedBLevel(data);
		int actual = act[0]*multipler;
		int expected = -7.13*multipler;
		QTRY_COMPARE(actual,expected);
	}
	void NormalizeSamples()
	{
		std::vector<double> actual = { -4, 0, 5, 6, 9 };
		std::vector<double> expected = { 0,0.3076923076923077,0.6923076923076923,0.7692307692307692,1 };
		FastFourierTransform ft;
		ft.Normalize(actual);
		
		for (size_t i = 0; i < actual.size(); i++)
		{
			QTRY_COMPARE(actual[i] * multipler, expected[i]*multipler);
		}
		//Q_ASSERT
	}
	void RootMeanSquare()
	{
		std::vector<double> tempData = { 5,3,2,1,-9,-2 };
		int expected = 4.54606056566 * multipler;
		FastFourierTransform cut;
		auto act = cut.RootMeanSquare(tempData, 6);
		Q_ASSERT(act.size() == 1);
		int actual = act[0] * multipler;
		QTRY_COMPARE(actual, expected);
	}

private:
	const int multipler = 100000;
};


QTEST_MAIN(FastFourierTransformTest)

#include "tester.moc"
