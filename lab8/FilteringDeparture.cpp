#include "FilteringDeparture.h"
FilteringDeparture::FilteringDeparture()
{
	departure = "";
}
FilteringDeparture::FilteringDeparture(string d)
{
	departure = d;
}

DynamicArray<Offer> FilteringDeparture::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> result;
	for (int i = 0; i < data.getLength(); i++)
		if (data.get(i).getDeparture() == departure)
			result.append(data.get(i));
	return result;
}