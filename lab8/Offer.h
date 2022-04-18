#pragma once

typedef enum {
	standard,city_break, cruise, all_inclusive
}offerType;

#include <string>
#include<iostream>

using namespace std;

class Offer {
	public:
		Offer();
		Offer(string i, float p, string dep, string dest, string sd, string ed, offerType t);
		float getPrice()const;
		string getId()const;
		string getDeparture()const;
		string getDestination()const;
		string getStart_date()const;
		string getEnd_date()const;
		offerType getType()const;

		void setPrice(float p);
		void setId(string i);
		void setDeparture(string d);
		void setDestination(string d);
		void setStart_date(string d);
		void setEnd_date(string d);
		void setType(offerType t);
		friend std::ostream& operator<<(std::ostream& s, const Offer& o);
		friend bool operator==(const Offer& a, const Offer& b);

	private:
		string id;
		float price;
		string departure, destination;
		string start_date, end_date;
		offerType type;

};

