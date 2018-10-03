#include "MediaManager.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
#include<qmessagebox.h>
#include<fstream>

Player* MediaManager::player = new Player();
Project* MediaManager::project = new Project();
GausianBlur* MediaManager::gBlur = new GausianBlur();
QList<VideoLoader*> MediaManager::widgets;
std::vector<std::string> MediaManager::mediaPaths;
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
	mediaPaths.emplace_back(path.toStdString());
}

 void MediaManager::Serialize(std::string path)
 {
	 fstream handle;
	 handle.open(path, std::ios::out);
	 cout << *player<<"\n";
	 handle << *player;
	 cout << *project;
	 handle << *project;
	/* for each (auto var in mediaPaths)
	 {
		 handle<<"#"
	 }*/
	 handle.close();
 }

 void MediaManager::Deserialize(std::string path)
 {
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
