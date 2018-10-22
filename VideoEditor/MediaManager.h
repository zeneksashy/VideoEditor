#pragma once
#include"Player.h"
#include<qwidget.h>
#include<qscopedpointer.h>
#include "VideoLoader.h"
#include "GausianBlur.h"
#include "Project.h"

class MediaManager
{
	friend class MediaManagerTest;
public:
	~MediaManager();
	MediaManager();
	static void LoadWidget(VideoLoader*);
	static void LoadMedia(QString);
	static  Player* player;
//	static  GausianBlur* gBlur;
	static Project* project;
	static void Serialize(std::string path);
	static void Deserialize(std::string path);
	static std::vector<std::string> getValuesFromString(std::string);
	static void Deserialize(std::vector<std::string>&);
	static void ClearAllWidgets();
private:
	static void LoadMediaToWidget(QString);
	static void LoadPlayer(QString);
	static QList<VideoLoader*>widgets;
	static std::vector<std::string> mediaPaths;
};

class MediaManagerTest
{
public:
	MediaManagerTest()
	{
	}

	~MediaManagerTest()
	{
	}

private:

};
