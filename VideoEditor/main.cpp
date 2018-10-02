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
	}
private:
	void serialization_tests()
	{
		SerializationTest cut;
		passed= cut.SettingsSerialization();
		(passed) ? std::cout << " TRUE == project serialization test passed\n" : std::cout << "FALSE == project serialization test not passed\n";
		passed = cut.SettingsDeserialization();
		(passed) ? std::cout << " TRUE == project deserialization test passed\n" : std::cout << "FALSE == project deserialization test not passed\n";

	}
	bool passed;
};

//TODO
// figure out how to store multiple effects in the player ( maybe vector with video effects*)
//serialize effects  with settings
// deserialize whole project
// change all tests
// -- add some kind of layout to time line
// -- alllow to shrink videos in time line
// adding new elemnts to time line on the same path
// add more effects
//add audio effects
//add rendering

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



