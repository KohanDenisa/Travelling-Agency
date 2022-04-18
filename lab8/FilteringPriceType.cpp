#include "FilteringPriceType.h"
//FilteringPriceType::FilteringPriceType()
//{
//	tf = standard;
//	pf = 0;
//}
//FilteringPriceType::FilteringPriceType(FilteringPrice p, FilteringType t)
//{
//	tf = t;
//	pf = p;
//}
DynamicArray FilteringPriceType::filter(DynamicArray& data)
{
	DynamicArray result;
	result = tf.filter(data);
	result = pf.filter(result);
	return result;
}