#include "FilteringPrice.h"
FilteringPrice::FilteringPrice()
{
	price = 0;
}
FilteringPrice::FilteringPrice(float p)
{
	price = p;
}

DynamicArray<Offer> FilteringPrice::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> result;
	for (int i = 0; i < data.getLength(); i++)
		if (data.get(i).getPrice() <= price)
			result.append(data.get(i));
	return result;
}