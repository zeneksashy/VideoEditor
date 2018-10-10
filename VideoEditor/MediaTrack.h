#pragma once
class MediaTrack
{
public:
	virtual ~MediaTrack();
	virtual void drawOutline() = 0;
	virtual void deleteOutline() = 0;
	virtual void ResizeFrame(int) = 0;
};

