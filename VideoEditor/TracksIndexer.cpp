#include "TracksIndexer.h"



TracksIndexer::TracksIndexer()
{
}


TracksIndexer::~TracksIndexer()
{
}

void TracksIndexer::AddNewTrack(SingleTrack *track)
{
	tracks.emplace_back(track);
}

void TracksIndexer::PlayVideo()
{
}

void TracksIndexer::CheckIfMediaIsAvaibleAt(int index)
{

}
