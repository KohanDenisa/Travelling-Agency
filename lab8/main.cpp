#include "Filtering.h"
#include "FilteringType.h"
#include "FilteringPrice.h"
#include "FilteringPriceType.h"

#include <iostream>
using namespace std;

#include "DynamicArray.h"

void displayMenu() {
	cout << "1.Add a new tourism offer" << endl;
	cout << "2.Display all the tourism offer" << endl;
	cout << "3.Filter the tourism offers by price (display all the tourism offers that have a price lower than a given price" << endl;
	cout << "4.Filter the tourism offers by type (for example, display all the city break type offers)" << endl;
	cout << "5.Filter the tourism offers by type and price (for example, display all the city break type offers that have a price lower than a given price)" << endl;
	cout << "6.Exit" << endl;
	cout << "Pick a command:" << endl;
}

Offer read_offer()
{
	string i, dep, dest, ed, sd;
	float p;
	int t;

	cout << "id:";
	cin >> i;
	cout << "price:";
	cin >> p;
	cout << "departure:";
	cin >> dep;
	cout << "destination:";
	cin >> dest;
	cout << "startdate:";
	cin >> sd;
	cout << "end date:";
	cin >> ed;
	cout << "offer type:";
	cin >> t;
	Offer o(i, p, dep, dest, sd, ed, offerType(t));
	return o;
}


void menu()
{
	while (1)
	{
		DynamicArray<Offer> arr;
		DynamicArray<Offer> arr1;
		DynamicArray<Offer> arr2;
		displayMenu();
		char x;
		Offer o;
		float p;
		int t;
		FilteringPrice price;
		FilteringType type;
		FilteringPriceType pt;
		cin >> x;
		if (x >= 'A' && x <= 'Z')
			x = x + 32;
		switch (x)
		{
		case 'a':
			o = read_offer();
			arr.append(o);
			break;
		case 's':
			for (unsigned int i = 0; i < arr.getLength(); i++) {
				cout << arr.get(i) << " ";
			}
			break;
		case 'p':
			cout << "price:";
			cin >> p;
			price = FilteringPrice(p);
			arr1 = price.filter(arr);
			for (unsigned int i = 0; i < arr1.getLength(); i++) {
				cout << arr1.get(i) << " ";
			}
			break;
		case 't':
			cout << "offer type:";
			cin >> t;
			type = FilteringType(offerType(t));
			arr2 = type.filter(arr);
			for (unsigned int i = 0; i < arr2.getLength(); i++) {
				cout << arr2.get(i) << " ";
			}
			break;
		case 'b':
			cout << "price:";
			cin >> p;
			cout << "type:";
			cin >> t;
			pt = FilteringPriceType(p, offerType(t));
			arr2 = pt.filter(arr);
			for (unsigned int i = 0; i < arr2.getLength(); i++) {
				cout << arr2.get(i) << " ";
			}
			break;
		case 'q':
			return;
		}
	}
}

int main() {

	//DynamicArray arr;
	/*arr.append("DynamicArray class");
	arr.append("NOT");
	arr.append("tested");*/
	
	/*cout << arr << endl;*/
	
	menu();
	
	return 0;
}