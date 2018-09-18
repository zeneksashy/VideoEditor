#pragma once
class MediaFrame
{
public:
	virtual ~MediaFrame();
	virtual void drawOutline() = 0;
	virtual void deleteOutline() = 0;
	virtual void ResizeFrame(int) = 0;
};

