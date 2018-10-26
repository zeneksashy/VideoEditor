#include "TracksIndexer.h"


void TracksIndexer::AddNewTrack(SingleTrack *track)
{
	tracks.emplace_back(track);
	//if(track->isVideoTrack())
		connect(track, &SingleTrack::ImageProcessed, this, &TracksIndexer::imageProcessed);
	connect(track, &SingleTrack::MediaAvailability, this, &TracksIndexer::MediaAvailabilityChanged);
}

bool TracksIndexer::isPlayerStopped()
{

	return false;
}

void TracksIndexer::Pause()
{
	for each (auto track in tracks)
	{
		track->PauseTrack();
	}
}

void TracksIndexer::Stop()
{
	for each (auto track in tracks)
	{
		track->StopTrack();
	}
}

void TracksIndexer::Play()
{
	bool videoTracksAvaible = true;
	for each (auto track in tracks)
	{
		if (track->isVideoTrack()&&videoTracksAvaible&& track->isTtrackAvaible())
		{
			track->PlayTrack();
			videoTracksAvaible = false;
		}
		else if (!track->isVideoTrack())
		{
			track->PlayTrack();
		}
	}
}

void TracksIndexer::MediaAvailabilityChanged(bool availability, SingleTrack* track)
{
	Pause();
	Play();
}

void TracksIndexer::CheckNextMedia(long pos)
{
	
}
void TracksIndexer::ClearAllTracks()
{
	tracks.clear();
}
void TracksIndexer::imageProcessed(const QImage &img)
{
	emit playerProcessedImage(img);
}