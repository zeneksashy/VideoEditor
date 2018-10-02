#pragma once
#include"VideoEffect.h"
#include<vector>
#include <opencv2/core/core.hpp>
using namespace std;
class EffectsContainer
{
public:
	EffectsContainer();
	~EffectsContainer();
	void AddEffect(VideoEffect*);
	void Run(cv::Mat&);
private:
	vector<VideoEffect*> videoEffects;
};

