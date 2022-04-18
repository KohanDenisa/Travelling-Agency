#include "FilteringType.h"



FilteringType::FilteringType(offerType t)
{
	type = t;
}
FilteringType::FilteringType()
{
	type = offerType(0);
}

DynamicArray<Offer> FilteringType::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> result;
	for (int i = 0; i < data.getLength(); i++)
		if (data.get(i).getType() == type)
			result.append(data.get(i));
	return result;
}