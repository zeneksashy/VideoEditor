#include "Tester.h"
#include <string>
#include <sstream>
#include "Project.h"
using namespace std;
bool SerializationTest::PlayerTest()
	{
		Player p;
		std::string path = "C:\\Users\\gzeniuk\\Downloads\\SampleVideo_720x480_30mb.mp4";
		std::stringstream strm;
		p.loadFile(QString::fromStdString(path));
		strm <<p;
		if (path.compare(strm.str()) == 0)
			return true;
		return false;
	}
bool SerializationTest::SettingsSerialization()
{
	Project p;
	ProjectSettings sett{ 1,2,3.5,"smth" };
	
	p.setProjectSettings(sett);
	stringstream strm;
	strm << p;
	if (settingsExpected.compare(strm.str()) == 0)
		return true;
	return false;
}

bool SerializationTest::EffectsSerialization()
{
	GausianBlur blur;
	GausianBlurParam params;
	params.Create(3.5, 4.2, 5, 11);
	blur.Initialize(params);
	stringstream strm;
	strm << blur;
	if (gaussianExpected.compare(strm.str()) == 0)
		return true;
	return false;
}

bool SerializationTest::SettingsDeserialization()
{
	Project p;
	p.Deserialize(settingsExpected);
	auto sett = p.getProjectSettings();
	ProjectSettings set{ 1,2,3.5,"smth" };
	if (set == sett)
		return true;
	return false;
}

bool SerializationTest::EffectsDeserialization()
{
	GausianBlurParam params;
	params.Create(3.5, 4.2, 5, 11);
	GausianBlur blur;
	blur.Deserialize(gaussianExpected);
	if (blur.getParams() == params)
		return true;
	return false;
}

bool SerializationTest::EffectContainerSerialization()
{
	GausianBlurParam params;
	params.Create(3.5, 4.2, 5, 11);
	GausianBlur blur;
	blur.Initialize(params);
	MedianBlur median;
	median.Initialize(5);
	EffectsContainer cont;
	cont.AddEffect(&blur);
	cont.AddEffect(&median);
	stringstream strm;
	strm << cont;
	if (effectContainerExpected.compare(strm.str())==0)
		return true;
	return false;
}

bool SerializationTest::MediaManagerDeserialization()
{
	//std::string path = "C:\\Users\\gzeniuk\\Desktop\\test.ediproj";
	//MediaManager::Deserialize(path);
	cout << "Media manager deserialization test not implemented ";
	return false;
}
