#pragma once
#include<string>
#include<vector>
struct ProjectSettings
{
	int frameWidth;
	int frameHeight;
	float frameRate;
	std::string path;
	bool operator==(const ProjectSettings& sett)
	{
		if (sett.frameHeight != this->frameHeight)
			return false;
		if (sett.frameWidth != this->frameWidth)
			return false;
		if (sett.frameRate != this->frameRate)
			return false;
		return true;
	}
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
	void Deserialize(std::vector<std::string>&);
	friend std::ostream& operator<<(std::ostream& os, const Project& proj);
private:
	ProjectSettings settings;
};

