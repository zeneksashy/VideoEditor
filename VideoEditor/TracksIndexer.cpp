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

void TracksIndexer::Pause()
{
	tracks[0]->PauseTrack();
}

void TracksIndexer::Stop()
{
	tracks[0]->StopTrack();
}

void TracksIndexer::Play()
{
	tracks[0]->PlayTrack();
}

void TracksIndexer::CheckIfMediaIsAvaibleAt(long index)
{

}
