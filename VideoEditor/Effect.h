#pragma once
class Effect
{
public:
	Effect();
	virtual ~Effect();
	virtual void ExecuteEffect()=0;
	virtual void Calculate() = 0;
};

