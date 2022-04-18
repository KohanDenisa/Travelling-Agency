#pragma once
#include "Filtering.h"
class FilteringType :public Filtering
{
public:
	FilteringType(offerType t);
	FilteringType();
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);
private:
	offerType type;
};