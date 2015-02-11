#include "database/address_data.h"


std::string address_data::get_address_one()  const
{
	return _street_address_one;
}
void address_data::set_address_one(std::string address)
{
	_street_address_one = address;
}

std::string address_data::get_address_two() const
{
	return _street_address_two;
}
void address_data::set_address_two(std::string address)
{
_street_address_two = address; 
}

std::string address_data::get_zip() const
{
return _zip;
}
void address_data::set_zip(std::string zip)
{
	_zip = zip;
}

void address_data::set_city(std::string city)
{
	_city = city;
}
std::string address_data::get_city() const
{
return _city;
}

void address_data::set_state(std::string state)
{
_state = state;
}

std::string address_data::get_state() const
{
return _state;
}

address_data::address_data()
{

}
address_data::~address_data()
{

}


