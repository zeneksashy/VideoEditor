#include "Project.h"



Project::Project()
{
}


Project::~Project()
{
}

ProjectSettings Project::getProjectSettings()
{
	return settings;
}

void Project::setProjectSettings(ProjectSettings settings)
{
	this->settings = settings;
}

void Project::Serialize(std::string)
{
}

void Project::Deserialize(std::string)
{
}
