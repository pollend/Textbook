#ifndef	_ADRESS_DATA_H
#define	_ADRESS_DATA_H
#include <string>

class address_data
{

private:
	std::string _street_address_one;
	std::string _street_address_two;
	std::string _zip;
	std::string _city;
	std::string _state;
public:

	std::string get_address_one() const;
	void set_address_one(std::string addresss);

	std::string get_address_two() const;
	void set_address_two(std::string addresss);

	std::string get_zip() const;
	void set_zip(std::string zip);

	void set_city(std::string city);
	std::string get_city() const;

	void set_state(std::string city);
	std::string get_state() const;

	address_data();
	~address_data();

	template<class Action>
    void persist(Action& a)
    {

    }
	
};

#endif