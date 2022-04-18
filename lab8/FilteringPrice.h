#pragma once
#include "Filtering.h"
class FilteringPrice :public Filtering
{
public:
	FilteringPrice();
	FilteringPrice(float p);
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);
private:
	float price;
};