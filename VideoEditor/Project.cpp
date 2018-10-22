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

void Project::Serialize(std::string path)
{

}

void Project::Deserialize(std::string value)
{
   // auto values =	MediaManager::getValuesFromString(value);
	//Deserialize(values);
	std::cout << "project deserialization  not implemented" ;
}

void Project::Deserialize(std::vector<std::string>& strngs)
{
	for (size_t i = 0; i < strngs.size(); i++)
	{
		if (strngs[i] == "Width")
		{
			settings.frameWidth = std::stoi(strngs[i + 1]);
			continue;
		}
		if (strngs[i] == "Height")
		{
			settings.frameHeight = std::stoi(strngs[i + 1]);
			continue;
		}
		if (strngs[i] == "FrameRate")
		{
			settings.frameRate = std::stof(strngs[i + 1]);
			continue;
		}
	}
}

std::ostream & operator<<(std::ostream & os, const Project & proj)
{
	os << "#Project#" << "#Settings#" <<"#Video#"<<"#Width#"
		<<proj.settings.frameWidth<<"#W"<<"#Height#"<<proj.settings.frameHeight<<"#H"
		<<"#FrameRate# "<<proj.settings.frameRate<<"#F"<<"#V"<< "#S" << "#P";
	return os;
}
