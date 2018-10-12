#include "VideoEditor.h"
#include "Tester.h"
#define TEST true;
#ifdef TEST
class Tests
{
public:
	Tests() :passed(false) {}
	void ConfigureConsole()
	{
		AllocConsole();
		AttachConsole(GetCurrentProcessId());
		freopen("CON", "w", stdout);
		freopen("conin$", "r", stdin);
		freopen("conout$", "w", stdout);
		freopen("conout$", "w", stderr);
	}
	void RunTests()
	{
		serialization_tests();
		audio_tests();
		video_tests();
	}
private:
	void video_tests()
	{
		GausianBlurTest gaussTest;
		passed = gaussTest.GausianBlurParamsNonOddNumbers();
	}
	void audio_tests()
	{
		FastFourierTransformTest  fftTest;
		passed = fftTest.CalculatedBLevel();
		passed = fftTest.NormalizeSamples();
		passed = fftTest.RootMeanSquare();
		AudioRecognitionTest recTest;
		passed = recTest.AudioFormatRegonitionTest_SampleSize32();
		passed= recTest.AudioFormatRegonitionTest_SampleSize8();
		AudioAnalyserTest analyserTest;
		passed = analyserTest.ConvertDataS16S();
	}
	void serialization_tests()
	{
		SerializationTest cut;
		passed= cut.SettingsSerialization();
		(passed) ? std::cout << " TRUE == project serialization test passed\n" : std::cout << "FALSE == project serialization test not passed\n";
		passed = cut.SettingsDeserialization();
		(passed) ? std::cout << " TRUE == project deserialization test passed\n" : std::cout << "FALSE == project deserialization test not passed\n";
		passed = cut.EffectsSerialization();
		(passed) ? std::cout << " TRUE == gaussian serialization test passed\n" : std::cout << "FALSE == gaussian serialization  test not passed\n";
		passed = cut.EffectsDeserialization();
		(passed) ? std::cout << " TRUE == gaussian deserialization test passed\n" : std::cout << "FALSE == gaussian deserialization  test not passed\n";
		passed = cut.EffectContainerSerialization();
		(passed) ? std::cout << " TRUE == effect container serialization test passed\n" : std::cout << "FALSE == effect container serialization  test not passed\n";
		passed = cut.MediaManagerDeserialization();
		(passed) ? std::cout << " TRUE == effect container serialization test passed\n" : std::cout << "FALSE == effect container serialization  test not passed\n";
	}
	bool passed;
};

//TODO
//serialize effects  with settings
// deserialize whole project -- player video path to serialize
// change all tests
// -- add some kind of layout to time line
// -- alllow to shrink videos in time line
// adding new elemnts to time line on the same path
// add more effects
//add audio effects
//add rendering
// create audio and video frames in another thread 
//create buffer for player opencv mat based on queue

int main(int argc, char *argv[])
{
	Tests t;
	t.ConfigureConsole();
	t.RunTests();
	QApplication a(argc, argv);
	VideoEditor w;
	w.show();
	return a.exec();
}
#endif // TEST
#ifndef TEST
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VideoEditor w;
	w.show();
	return a.exec();
}
#endif // !TEST



