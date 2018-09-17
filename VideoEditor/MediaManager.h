#pragma once
#include"Player.h"
#include<qwidget.h>
#include<qscopedpointer.h>
#include "VideoLoader.h"
class MediaManager
{
public:
	~MediaManager();
	MediaManager();
	static void LoadWidget(VideoLoader*);
	static void LoadMedia(QString);
	static  Player* player;
private:
	static void LoadMediaToWidget(QString);
	static void LoadPlayer(QString);
	static QList<VideoLoader*>widgets;
};

