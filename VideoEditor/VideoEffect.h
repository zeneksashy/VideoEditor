#pragma once
class VideoEffect
{
public:
	VideoEffect() {};
	virtual ~VideoEffect() {};
	virtual void ExecuteEffect()=0;
	virtual void Calculate() = 0;
};

