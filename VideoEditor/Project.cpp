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

void Project::Serialize()
{
}

void Project::Deserialize()
{
}
