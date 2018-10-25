#include "VideoEffect.h"

std::ostream & operator<<(std::ostream & os, const VideoEffect & effect)
{
	effect.Print(os);
	return os;
}
