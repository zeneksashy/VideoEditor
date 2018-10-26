#pragma once
#include"SingleTrack.h"
class SingleTrack;
class TracksIndexer: public QObject
{
	Q_OBJECT
public:
	TracksIndexer():stop(true){}
	void ClearAllTracks();
	void AddNewTrack(SingleTrack*);
	bool isPlayerStopped();
public slots:
	void Play();
	void Pause();
	void Stop();
private slots:
	void MediaAvailabilityChanged(bool,SingleTrack*);
	void imageProcessed(const QImage& img);
signals:
	void positionChanged();
	void videoStopped();
	void playerProcessedImage(const QImage& img);
private:
	bool stop;
	void CheckNextMedia(long pos);
	std::vector<SingleTrack*>tracks;
};

