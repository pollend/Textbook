#ifndef	_AIRPORTS_DATA_H
#define	_AIRPORTS_DATA_H
#include <string>
#include <Wt/Dbo/Dbo>
#include <string>
#include "database/data.h"
#include "database/address_data.h"
#include "database/database.h"
#include "database/business_data.h"
#include "database/image_data.h"

namespace dbo = Wt::Dbo;
class business_data;
class airport_data 
{

private:
	//dbo::collection< dbo::ptr<image_data> > _images;
	std::string _airport_name;
	std::string _airport_short;

	std::string _phone_awos;
	std::string _phone_ctaf;
	std::string _phone_fss;
	std::string _phone_office;

	std::string _frequency_awos;
	std::string _frequency_ctaf;
	std::string _frequency_fss;
	std::string _frequency_office;

	std::string _cost;

	std::string _operational_hours;

	std::string _description;
	std::string _approach;

	std::string _location;

	std::string _latitude;
	std::string _longitude;

	std::string _fuel;
	std::string _repairs;


	bool _verify_phone(std::string number);
public:

	dbo::collection< dbo::ptr<business_data> > business;


	airport_data();
	~airport_data();
	

	void set_airport_name(std::string airport);
	std::string get_airport_name() const;

	void set_airport_short_name(std::string airport);
	std::string get_airport_short_name() const;
	
	void set_cost(std::string cost);
	std::string get_cost() const;

	bool set_awos_frequency(std::string frequency);
	bool set_ctaf_frequency(std::string frequency);
	bool set_fss_frequency(std::string frequency);
	bool set_office_frequency(std::string frequency);
	
	bool set_awos_phone(std::string phone);
	bool set_ctaf_phone(std::string phone);
	bool set_fss_phone(std::string phone);
	bool set_office_phone(std::string phone);

	std::string get_awos_frequency() const;
	std::string get_ctaf_frequency() const;
	std::string get_fss_frequency() const;
	std::string get_office_frequency() const;

	std::string get_awos_phone() const;
	std::string get_ctaf_phone() const;
	std::string get_fss_phone() const;
	std::string get_office_phone() const;

	std::string get_description() const;
	void set_descrption(std::string descrption);

	std::string get_longitude() const;
	void set_longitude(std::string location);

	std::string get_latitude() const;
	void set_latitude(std::string location);


	std::string get_fuel() const;
	void set_fuel(std::string fuel);

	void set_repairs(std::string repairs);
	std::string get_repairs() const;

	template<class Action>
    void persist(Action& a)
    {
		dbo::hasMany(a, business, dbo::ManyToOne, AIRPORTS);

		dbo::field(a,_airport_name,"name");
		dbo::field(a,_airport_short,"name_short");

		dbo::field(a,_phone_awos,"phone_awos");
		dbo::field(a,_phone_ctaf,"phone_ctaf");
		dbo::field(a,_phone_fss,"phone_fss");
		dbo::field(a,_phone_office,"phone_office");

		dbo::field(a,_frequency_awos,"freequency_awos");
		dbo::field(a,_frequency_ctaf,"freequency_ctaf");
		dbo::field(a,_frequency_fss,"freequency_fss");
		dbo::field(a,_frequency_office,"freequency_office");

		dbo::field(a,_cost,"cost");
		dbo::field(a,_operational_hours,"operational_hours");
		dbo::field(a,_description,"description");
		dbo::field(a,_approach,"approach");
		dbo::field(a,_location,"location");
		dbo::field(a,_fuel,"fuel");
		dbo::field(a,_repairs,"repair");

	}

  

};

#endif

