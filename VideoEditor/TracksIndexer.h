#pragma once
#include"SingleTrack.h"
class TracksIndexer
{
public:
	TracksIndexer();
	~TracksIndexer();
	void AddNewTrack(SingleTrack*);
	void PlayVideo();
private:
	void CheckIfMediaIsAvaibleAt(int index);

	std::vector<SingleTrack*>tracks;
};

