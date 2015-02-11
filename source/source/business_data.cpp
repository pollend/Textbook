#include "database/business_data.h"

business_data::business_data()
{

}

business_data::~business_data()
{

}


std::string business_data::get_adress_one() const
{
	return _street_address_one;
}
void business_data::set_adress_one(std::string address)
{
	_street_address_one = address;
}

std::string business_data::get_adress_two() const
{
	return _street_address_two;
}
void business_data::set_adress_two(std::string address)
{
	_street_address_two = address;
}

std::string business_data::get_website() const
{
	return _website;
}
void business_data::set_website(std::string website)
{
	_website = website;
}

std::string business_data::get_email() const
{
	return _email;
}
void business_data::set_email(std::string email)
{
	_email = email;
}

std::string business_data::get_zip() const
{
	return _zip;
}
void business_data::set_zip(std::string zip)
{
	_zip = zip;
}

std::string business_data::get_city() const
{
	return _city;
}
std::string business_data::set_city(std::string city)
{
	_city = city;
	
}
