#pragma once
#include "Filtering.h"
class FilteringDeparture :public Filtering
{
public:
	FilteringDeparture();
	FilteringDeparture(string d);
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);
private:
	string departure;
};