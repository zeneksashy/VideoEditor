#pragma once
#include"Player.h"
#include<qwidget.h>
#include<qscopedpointer.h>
#include "VideoLoader.h"
#include "GausianBlur.h"
class MediaManager
{
public:
	~MediaManager();
	MediaManager();
	static void LoadWidget(VideoLoader*);
	static void LoadMedia(QString);
	static  Player* player;
	static  GausianBlur* gBlur;
private:
	static void LoadMediaToWidget(QString);
	static void LoadPlayer(QString);
	static QList<VideoLoader*>widgets;
};

