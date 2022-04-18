#include "Offer.h"


Offer::Offer()
{
	id = "";
	price = 0.0;
	departure = "";
	destination = "";
	start_date = "";
	end_date = "";
	type = offerType(0);
}


float Offer::getPrice() const
{
	return price;
}


string Offer::getId() const
{
	return id;
}

Offer::Offer(string i, float p, string dep, string dest, string sd, string ed, offerType t)
{
	id = i;
	price = p;
	departure = dep;
	destination = dest;
	start_date = sd;
	end_date = ed;
	type = t;
}

string Offer::getDeparture() const
{
	return departure;
}


string Offer::getDestination() const
{
	return destination;
}

string Offer::getStart_date() const
{
	return start_date;
}

offerType Offer::getType() const
{
	return type;
}

string Offer::getEnd_date() const
{
	return end_date;
}

void Offer::setPrice(float p)
{
	price = p;
}

void Offer::setId(string i)
{
	id = i;
}

void Offer::setDeparture(string d)
{
	departure = d;
}

void Offer::setDestination(string d)
{
	destination = d;
}

void Offer::setStart_date(string d)
{
	start_date = d;
}

void Offer::setEnd_date(string d)
{
	end_date = d;
}

void Offer::setType(offerType t)
{
	type = t;
}

ostream& operator<<(ostream& s, const Offer& o) {
	// [1 2 3 4 5 ]
	//s << "[";
	//for (unsigned int i = 0; i < arr.length; i++) {
	//	s << arr.data[i] << " ";
	//}
	//s << "]";
	s << "Offer with id:" << o.getId() << " has price" << o.getPrice() << ", departure:" << o.getDeparture() 
		<< ", destination:" << o.getDestination() << ", start date:" << o.getStart_date() << ", end date:"
		<< o.getEnd_date() << " and type:" << o.getType();
	return s;
	}

bool operator==(const Offer& a, const Offer& b)
{
	if (a.getId() == b.getId() && a.getPrice() == b.getPrice() && a.getDeparture() == b.getDeparture() && a.getDestination() == b.getDestination() && a.getStart_date() == b.getStart_date() && a.getEnd_date() == b.getEnd_date() && a.getType() == b.getType())
		return true;
	else
		return 0;
}