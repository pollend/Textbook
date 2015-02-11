#include "database/airport_data.h"


airport_data::airport_data()
{

	_airport_name= std::string();
	_airport_short= std::string();
	_phone_awos= std::string();
	_phone_ctaf= std::string();
	_phone_fss= std::string();
	_phone_office= std::string();
	_frequency_awos= std::string();
	_frequency_ctaf= std::string();
	_frequency_fss= std::string();
	_frequency_office= std::string();
	_cost= std::string();
	_operational_hours= std::string();
	_description= std::string();
	_approach= std::string();
	_location= std::string();
	_fuel= std::string();
	_repairs = std::string();
	_latitude = std::string();
	_longitude= std::string();


}
airport_data::~airport_data()
{

}


bool airport_data::_verify_phone(std::string number)
{
	return true;
}

/*##############################################################################
#Airport name
##############################################################################*/


void airport_data::set_airport_name(std::string airport)
{
	_airport_name = airport;

}

std::string airport_data::get_airport_name() const
{
	return _airport_name;
}

void airport_data::set_airport_short_name(std::string airport)
{
	_airport_short = airport;
}

std::string airport_data::get_airport_short_name() const
{
	return _airport_short;

}


/*##############################################################################
#Cost
##############################################################################*/

void airport_data::set_cost(std::string cost)
{
	_cost = cost;
}


std::string airport_data::get_cost() const
{
	return _cost;
}


/*##############################################################################
#frequency
##############################################################################*/
bool airport_data::set_awos_frequency(std::string frequency)
{
	_frequency_awos = frequency;
}
bool airport_data::set_ctaf_frequency(std::string frequency)
{
	_frequency_ctaf = frequency;
}
bool airport_data::set_fss_frequency(std::string frequency)
{
	_frequency_fss = frequency;	
}
bool airport_data::set_office_frequency(std::string frequency)
{
	_frequency_office = frequency;
}

std::string airport_data::get_awos_frequency() const
{
	return _frequency_awos;	
}
std::string airport_data::get_ctaf_frequency() const
{
	return _frequency_ctaf;
}
std::string airport_data::get_fss_frequency() const
{
	return _frequency_fss;
}
std::string airport_data::get_office_frequency() const
{
	return _frequency_office;
}

/*##############################################################################
#phone
##############################################################################*/
bool airport_data::set_awos_phone(std::string phone)
{
	if(_verify_phone(phone))
	{
		_phone_awos= phone;
		return true;

	}
	return false;
}
bool airport_data::set_ctaf_phone(std::string phone)
{
	if(_verify_phone(phone))
	{
		_phone_ctaf = phone;
		return true;

	}
	return false;
	
}
bool airport_data::set_fss_phone(std::string phone)
{
	if(_verify_phone(phone))
	{
		_phone_fss= phone;
		return true;

	}
	return false;
}
bool airport_data::set_office_phone(std::string phone)
{
	if(_verify_phone(phone))
	{
		_phone_office= phone;
		return true;
	}
	return false;
}

std::string airport_data::get_awos_phone() const
{
return _phone_awos;
}

std::string airport_data::get_ctaf_phone() const
{
return _phone_ctaf;
}

std::string airport_data::get_fss_phone() const
{
return _phone_fss;
}

std::string airport_data::get_office_phone() const
{
	return _phone_office;
}

/*##############################################################################
#desccription
##############################################################################*/
std::string airport_data::get_description() const
{
	return _description;
}

void airport_data::set_descrption(std::string descrption)
{airport_data::
	_description = descrption;
}

/*##############################################################################
#location
##############################################################################*/

	std::string airport_data::get_longitude() const
	{
		return _longitude;
	}
	void airport_data::set_longitude(std::string longitude)
	{
		_longitude = longitude;
	}

	std::string airport_data::get_latitude() const
	{
		return _latitude;
	}
	void airport_data::set_latitude(std::string latitude)
	{
		_latitude = latitude;
	}



/*##############################################################################
#fuel
##############################################################################*/

std::string airport_data::get_fuel() const
{
	return _fuel;
}
void airport_data::set_fuel(std::string fuel)
{
	_fuel = fuel;
}


/*##############################################################################
#repair
##############################################################################*/


void airport_data::set_repairs(std::string repairs)
{
	_repairs = repairs;
}
std::string airport_data::get_repairs() const
{
	return _repairs;
}


