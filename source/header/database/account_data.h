#ifndef	_ACCOUNT_DATA_H
#define	_ACCOUNT_DATA_H
#include <string>

class account_data
{

private:
	std::string name;
	std::string password;
public:
	bool login(std::string name, std::string password);

	void set_password(std::string password);
	void set_user(std::string user);
	void set_password(std::string password);

	account_data();
	~account_data();

	template<class Action>
    void persist(Action& a)
    {

    }
	
};

#endif