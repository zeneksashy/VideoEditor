#pragma once
#include<string>
struct ProjectSettings
{
	int frameWidth;
	int frameHeight;
	double frameRate;
	std::string path;
};
class Project
{
public:
	Project();
	~Project();
	ProjectSettings getProjectSettings();
	void setProjectSettings(ProjectSettings);
	void Serialize();
	void Deserialize();
private:
	ProjectSettings settings;
};

