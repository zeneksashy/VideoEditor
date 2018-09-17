#include "MediaManager.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
#include<qmessagebox.h>

Player* MediaManager::player = new Player();
QList<VideoLoader*> MediaManager::widgets;
MediaManager::~MediaManager()
{
	delete player;
}
void MediaManager::LoadWidget(VideoLoader* widget)
{
	widgets.push_back(widget);
}
 void MediaManager::LoadMedia(QString path)
{
	LoadPlayer(path);
	LoadMediaToWidget(path);
}

 void MediaManager::LoadMediaToWidget(QString path)
 {
	 for each (auto widget in widgets)
	 {
		 widget->loadFile(path);
	 }
 }

 void MediaManager::LoadPlayer(QString path)
{
	 Player pl = new Player();
	if (!player->loadFile(path))
	{
		QMessageBox msgBox;
		msgBox.setText("The selected video could not be opened!");
		msgBox.exec();
	}
}
