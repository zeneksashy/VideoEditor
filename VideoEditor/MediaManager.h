#pragma once
#include"Player.h"
#include<qwidget.h>
#include<qscopedpointer.h>
#include "VideoLoader.h"
class MediaManager
{
public:
	//~MediaManager();
	static void LoadWidget(VideoLoader*);
	static void LoadMedia(QString);
	//static Player getPlayer();
	static  Player player;
private:
	static void LoadMediaToWidget(QString);
	static void LoadPlayer(QString);
	
	//static std::list<QWidget> widgets;
	static QList<VideoLoader*>widgets;
};

