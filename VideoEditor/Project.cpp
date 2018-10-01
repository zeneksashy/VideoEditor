#include "Project.h"
#include <sstream>
#include<iostream>
#include<map>
#include<vector>
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

void Project::Deserialize(std::string path)
{
	std::string tempstring = path;
	std::string temp = "";
	std::vector<std::string> strngs;
	int i = 0;
	char next;
	std::map<char, int> hashes;
	while (i < tempstring.length())
	{

		if (tempstring[i] == '#')
		{
			if (tempstring[i + 1] != '#')
			{
				auto it = hashes.find(tempstring[i + 1]);
				if (it != hashes.end())
				{
					hashes[tempstring[i + 1]] += 1;
					++i;
				}
				else
				{
					hashes[tempstring[i + 1]] = 1;
				}
			}
			if(temp!="")
				strngs.push_back(temp);
			temp = "";
		}
		else
		{
			temp += tempstring[i];
		}
		++i;
	}
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
			settings.frameRate = std::stod(strngs[i + 1]);
			continue;
		}	
	}
}

std::string Project::Split(std::string sub)
{

	return std::string();
}

std::ostream & operator<<(std::ostream & os, const Project & proj)
{
	os << "#Project#" << "#Settings#" <<"#Video#"<<"#Width#"
		<<proj.settings.frameWidth<<"#W"<<"#Height#"<<proj.settings.frameHeight<<"#H"
		<<"#FrameRate# "<<proj.settings.frameRate<<"#F"<<"#V"<< "#S" << "#P";
	return os;
}

//std::istream & operator>>(std::istream & is, const Project & proj)
//{
//	return is;
//	// TODO: insert return statement here
//}
