#include "MediaManager.h"


Player* MediaManager::player = new Player();
Project* MediaManager::project = new Project();
//GausianBlur* MediaManager::gBlur = new GausianBlur();
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
	 handle << "#MediaPaths#";
	 for each (auto var in mediaPaths)
	 {
		 handle << "#Path#" << var << "#P";
	 }
	 handle << "#M";
	 handle.close();
 }

 void MediaManager::Deserialize(std::string path)
 {
	 fstream handle;
	 std::string line;
	 std::string buf="";
	 handle.open(path, std::ios::in);
	 while (!handle.eof())
	 {
		 handle >> line;
		 buf += line;
	 }
	 auto values = getValuesFromString(buf);
	 project->Deserialize(values);
	 player->Deserialize(values);
	 Deserialize(values);
 }

 std::vector<std::string> MediaManager::getValuesFromString(std::string deserialized)
 {
	 std::string temp = "";
	 std::vector<std::string> strings;
	 int i = 0;
	 char next;
	 std::map<char, int> hashes;
	 while (i < deserialized.length())
	 {
		 if (deserialized[i] == '#')
		 {
			 if (deserialized[i + 1] != '#')
			 {
				 auto it = hashes.find(deserialized[i + 1]);
				 if (it != hashes.end())
				 {
					 hashes[deserialized[i + 1]] += 1;
					 if (hashes[deserialized[i + 1]] == 2)
					 {
						 hashes[deserialized[i + 1]] = 1;
						 if (temp != "")
							 strings.emplace_back(temp);
						 temp = "";
					 }
					 else
					 {
						 ++i;
					 }

				 }
				 else
				 {
					 hashes[deserialized[i + 1]] = 1;
				 }
			 }
			 if (temp != "")
				 strings.emplace_back(temp);
			 temp = "";
		 }
		 else
		 {
			 temp += deserialized[i];
		 }
		 ++i;
	 }
	 return strings;
 }

 void MediaManager::Deserialize(std::vector<std::string>&x )
 {
	 for (size_t i = 0; i < x.size(); i++)
	 {
		 if (x[i] == "Path")
		 {
			 LoadMedia(QString::fromStdString(x[i + 1]));
			 continue;
		 }
	 }
 }

 void MediaManager::ClearAllWidgets()
 {
	 widgets.clear();
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
	if (!player->loadFile(path))
	{
		QMessageBox msgBox;
		msgBox.setText("The selected video could not be opened!");
		msgBox.exec();
		return;
	}
}
