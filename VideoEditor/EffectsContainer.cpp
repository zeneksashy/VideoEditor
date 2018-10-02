#include "EffectsContainer.h"



EffectsContainer::EffectsContainer()
{
}


EffectsContainer::~EffectsContainer()
{
}

void EffectsContainer::AddEffect(VideoEffect * e)
{
	videoEffects.emplace_back(e);
}

void EffectsContainer::Run(cv::Mat& frame)
{
	for each (auto e in videoEffects)
	{
		e->Calculate(frame);
	}
}
