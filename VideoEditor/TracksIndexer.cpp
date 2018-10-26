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
	return stop;
}

void TracksIndexer::Pause()
{
	if (!stop)
	{
		for each (auto track in tracks)
		{
			track->PauseTrack();
		}
		stop = true;
	}
		
}

void TracksIndexer::Stop()
{
	if (!stop)
	{
		for each (auto track in tracks)
		{
			track->StopTrack();
		}
		stop = true;
	}
}

void TracksIndexer::Play()
{
	if (stop)
	{
		bool videoTracksAvaible = true;
		for each (auto track in tracks)
		{
			if (track->isVideoTrack() && videoTracksAvaible&& track->isTtrackAvaible())
			{
				track->PlayTrack();
				videoTracksAvaible = false;
			}
			else if (!track->isVideoTrack() && track->isTtrackAvaible())
			{
				track->PlayTrack();
			}
		}
		stop = false;
	}
}

void TracksIndexer::MediaAvailabilityChanged(bool availability, SingleTrack* track)
{
	Pause();
	Play();
	//emit message with position that track has finished
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