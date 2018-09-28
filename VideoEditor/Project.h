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
	void Serialize(std::string);
	void Deserialize(std::string);
private:
	ProjectSettings settings;
};

