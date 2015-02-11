#ifndef	_BUSINESS_DATA_H
#define	_BUSINESS_DATA_H
#include <string>
#include <Wt/Dbo/Dbo>
#include <string>
#include "database/database.h"
#include "database/airport_data.h"

namespace dbo = Wt::Dbo;

class airport_data;
class business_data
{
private:
	dbo::ptr<airport_data> _airports;

	std::string _street_address_one;
	std::string _street_address_two;
	std::string _zip;
	std::string _city;
	std::string _state;
	std::string _website;
	std::string _email;

public:
	business_data();
	~business_data();
	
	std::string get_adress_one() const;
	void set_adress_one(std::string address);

	std::string get_adress_two() const;
	void set_adress_two(std::string address);

	std::string get_website() const;
	void set_website(std::string website);

	std::string get_email() const;
	void set_email(std::string email);

	std::string get_zip() const;
	void set_zip(std::string zip);

	std::string get_city() const;
	std::string set_city(std::string city);


	template<class Action>
	void persist(Action& a)
	{
		dbo::belongsTo(a, _airports, AIRPORTS);

		dbo::field(a,_street_address_one,"street_address_one");
		dbo::field(a, _street_address_two,"street_address_two");
		dbo::field(a, _zip, "zip");
		dbo::field(a, _city, "city");
		dbo::field(a, _website, "website");
		dbo::field(a, _email, "email");
	}
		
};

#endif