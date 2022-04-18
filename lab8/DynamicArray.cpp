#include "DynamicArray.h"
#include <iostream>
//#include "FilteringCriteria.h"
//#include "Offer.cpp"
using namespace std;

template <class ElementType>
DynamicArray<ElementType>::DynamicArray(int capacity) {
	length = 0;
	this->capacity = capacity;
	data = new ElementType[capacity]();

	if (data == nullptr) {
		cerr << "DynamicArray(): failed to allocate memory" << endl;
		exit(-1);
	}
}

template <class ElementType>
DynamicArray<ElementType>::~DynamicArray() {
	//free the allocated memory
	delete[] data;
}

template <class ElementType>
DynamicArray<ElementType>& DynamicArray<ElementType>::operator=(const DynamicArray& other) {

	if (this != &other) { // self assignment check
		// deep copy of other
		length = other.length;
		capacity = other.capacity;

		delete[] this->data;
		// !! data 
		// data = other.data; NOO! this is shallow copy
		// deep copy of data
		data = new ElementType[other.capacity]();

		if (data == nullptr) {
			cerr << "operator=(): failed to allocate memory" << endl;
			exit(-1);
		}

		for (unsigned int i = 0; i < length; i++)
			data[i] = other.data[i];
	}
	return *this; // the type of this is DynamicArray* -> dereferencing
}

template <class ElementType>
DynamicArray <ElementType>::DynamicArray(const DynamicArray& other) {
	// deep copy of other
	length = other.length;
	capacity = other.capacity;

	// !! data 
	// data = other.data; NOO! this is shallow copy
	// deep copy of data
	data = new ElementType[other.capacity]();

	if (data == nullptr) {
		cerr << "DynamicArray(const DynamicArray& other): failed to allocate memory" << endl;
		exit(-1);
	}

	for (unsigned int i = 0; i < length; i++)
		data[i] = other.data[i];
}

template <class ElementType>
void DynamicArray <ElementType>::append(ElementType v, bool* err)
{
	// todo 
	// check if the length < capacity
	if (length == capacity) {
		// double the capacity
		resize(capacity * 2);
	}
	data[length] = v;
	length++;
}

template <class ElementType>
ostream& operator<<(ostream& s, const DynamicArray <ElementType>& arr) {
	// [1 2 3 4 5 ]
	s << "[";
	for (unsigned int i = 0; i < arr.length; i++) {
		s << arr.data[i] << " ";
	}
	s << "]";
	return s;
}

template <class ElementType>
ElementType DynamicArray <ElementType>::popBack() {
	// delete and return the last element in the array
	// pre array is not empty
	if (length == 0) {
		// unfriendly way of handling corner cases
		cerr << "Precondition does not hold: popBack()" << endl;
		exit(-1);
	}
		
	// convention 0 - elements that were not set

	ElementType v = data[length];
	length--;

	return v;
}

template <class ElementType>
ElementType DynamicArray <ElementType>::remove(unsigned int index)
{
	//  index >= 0 and index < length
	// pre index >=0 and index < length
	if (index >= 0 && index < length) {
		ElementType v = data[index];
		for (unsigned int i = index; i < length - 1; i++)
			data[i] = data[i + 1];
		length--;
		return v;
	}
	else {
		// unfriendly way of handling corner cases
		cerr << "Precondition does not hold: remove()" << endl;
		exit(-1);
	}
}

template <class ElementType>
ElementType& DynamicArray <ElementType>::get(unsigned int index) {

	// pre index >=0 and index < length
	if (index >= 0 && index < length) {
		return data[index];
	}
	else {
		// unfriendly way of handling corner cases
		cerr << "Precondition does not hold: get()" << endl;
		exit(-1);
	}
}

template <class ElementType>
void DynamicArray <ElementType>::resize(unsigned int newCapacity) {

	this->capacity = newCapacity;
	// no realloc  in c++

	ElementType* newData = new ElementType[newCapacity]();
	if (newData == nullptr) {
		cerr << "resize(): failed to allocate memory" << endl;
		exit(-1);
	}
	// previous elements located in data
	// copy them in newData
	for (unsigned int i = 0; i < length; i++) {
		newData[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newData;
}

