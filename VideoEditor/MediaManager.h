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
private:
	static void LoadMediaToWidget(QString);
	static void LoadPlayer(QString);
	static  Player player;
	//static std::list<QWidget> widgets;
	static QList<VideoLoader*>widgets;
};

