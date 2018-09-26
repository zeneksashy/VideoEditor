#pragma once
#include "VideoEditor.h"
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

