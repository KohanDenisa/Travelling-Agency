#pragma once
#include "Filtering.h"
class FilteringCriteriaOr :public Filtering
{
public:

	DynamicArray<Offer> filter(DynamicArray<Offer>& data)
	{
		DynamicArray<Offer> r1 = c1->filter(data);
		DynamicArray<Offer> r2 = c2->filter(data);
		DynamicArray<Offer> r;
		for (int i = 0; i < r1.getLength(); i++)
			r.append(r1.get(i));
		for (int i = 0; i < r2.getLength(); i++)
		{ 
			int ok = 0;
			for (int j = 0; j < r1.getLength(); j++)
				if (r2.get(i) == r1.get(j))
					 ok = 1;
			if(ok==0)
			r.append(r2.get(i));
		}
			
		return r;
	}

private:
	Filtering* c1;
	Filtering* c2;
};