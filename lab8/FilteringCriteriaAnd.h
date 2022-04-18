#pragma once
#include "Filtering.h"
class FilteringCriteriaAnd :public Filtering
{
public:
	
	DynamicArray<Offer> filter(DynamicArray<Offer>& data)
	{
		DynamicArray<Offer> r = c1->filter(data);
		r = c2->filter(r);
		return r;
	}

private:
	Filtering *c1;
	Filtering *c2;
};