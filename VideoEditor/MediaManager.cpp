#include "MediaManager.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
#include<qmessagebox.h>

Player MediaManager::player;
QList<VideoLoader*> MediaManager::widgets;
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
		 widget->loadVideo(path);
	 }
 }

 void MediaManager::LoadPlayer(QString path)
{
	if (!player.loadVideo(path))
	{
		QMessageBox msgBox;
		msgBox.setText("The selected video could not be opened!");
		msgBox.exec();
	}
}
