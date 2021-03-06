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

void EffectsContainer::Deserialize(std::string )
{
}

void EffectsContainer::Deserialize(std::vector<std::string>&x)
{
	for each (auto e in videoEffects)
	{
		e->Deserialize(x);
	}
}

std::ostream & operator<<(std::ostream & os, const EffectsContainer & container)
{
	for each (auto e in container.videoEffects)
	{
		os << *e;
	}
	return os;
	// TODO: insert return statement here
}
