#include "pch.h"
#include <complex>
#include <valarray>
//C:\Qt\5.11.1\msvc2017_64\include\QtMultimedia
#include"C:/Qt/5.11.1/msvc2017_64/include/QtMultimedia/qaudiobuffer.h"
#include"C:/Qt/5.11.1/msvc2017_64/include/QtMultimedia/qaudioformat.h"
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(AudioRecognitionTEST, RecognizeFormat)
{
	QAudioFormat format();


}
TEST(FFTCalculation, CalculateArray) {
	
	std::complex<double> test[] = { 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 };
	std::complex<double> original[] = { 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 };
	//FFT < 8, std::complex<double> > fft;
	std::valarray<std::complex<double>> data(test, 8);
	FastFourierTransform ft;
	ft.Execute*(data);
	EXPECT_EQ(test, original);
}