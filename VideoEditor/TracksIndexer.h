#pragma once
#include"SingleTrack.h"
class SingleTrack;
class TracksIndexer
{
public:
	TracksIndexer();
	~TracksIndexer();
	void AddNewTrack(SingleTrack*);
public slots:
	void Play();
	void Pause();
	void Stop();
private:
	void CheckIfMediaIsAvaibleAt(long index);
	std::vector<SingleTrack*>tracks;
};

