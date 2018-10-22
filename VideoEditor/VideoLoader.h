#pragma once
#include <QWidget>
class VideoLoader
{

public:
	virtual void loadFile(QString) = 0;
	VideoLoader();
	~VideoLoader();
};
