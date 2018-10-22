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
		gui_tests();
	}
private:
	void gui_tests()
	{		
		TimeLineTest timeLine;
		passed = timeLine.NewTrackTest();
		write_result("NewTrackTest");
		passed = timeLine.timeLabelSecondsParse();
		write_result("timeLabelSecondsParse");
	}
	void video_tests()
	{
		GausianBlurTest gaussTest;
		passed = gaussTest.GausianBlurParamsNonOddNumbers();
		write_result("gaussian blur params");
	}
	void audio_tests()
	{
		FastFourierTransformTest  fftTest;
		passed = fftTest.CalculatedBLevel();
		write_result("calculate dB level");
		passed = fftTest.NormalizeSamples();
		write_result("Normalization");
		passed = fftTest.RootMeanSquare();
		write_result("RootMeanSquare");
		AudioRecognitionTest recTest;
		passed = recTest.AudioFormatRegonitionTest_SampleSize8();
		write_result("AudioFormatRegonitionTest_SampleSize8");
		passed = recTest.AudioFormatRegonitionTest_SampleSize32();
		write_result("AudioFormatRegonitionTest_SampleSize32");
		AudioAnalyserTest analyserTest;
		passed = analyserTest.ConvertDataS16S();
		write_result("ConvertDataS16S");
	}
	void serialization_tests()
	{
		SerializationTest cut;
		passed= cut.SettingsSerialization();
		write_result("project serialization");
		passed = cut.SettingsDeserialization();
		write_result("project deserialization");
		passed = cut.EffectsSerialization();
		write_result("gaussian serialization");
		passed = cut.EffectsDeserialization();
		write_result("gaussian deserialization");
		passed = cut.EffectContainerSerialization();
		write_result("effect container serialization");
		passed = cut.MediaManagerDeserialization();
		write_result("effect container deserialization");
	}
	void write_result(std::string name)
	{
		(passed) ? std::cout << " TRUE == " << name << " test passed\n" : std::cout << " FALSE == " << name << " test not passed\n";
	}
	bool passed;
};
//TODO
//serialize effects  with settings
// deserialize whole project -- player video path to serialize
// change all tests
// -- add some kind of layout to time line
// -- alllow to shrink videos in time line
// adding new elemnts to time line on the same path-- half done
// add more effects
//add audio effects
//add rendering
// create audio and video frames in another thread 
//create buffer for player opencv mat based on queue- done
int main(int argc, char *argv[])
{
	Tests t;
	t.ConfigureConsole();
	QApplication a(argc, argv);
	t.RunTests();
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



