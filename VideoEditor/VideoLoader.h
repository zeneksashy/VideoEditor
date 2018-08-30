#pragma once

#include <QWidget>


class VideoLoader
{


public:
	virtual void loadVideo(QString) = 0;
	VideoLoader();
	~VideoLoader();
};
