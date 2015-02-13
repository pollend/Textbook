#ifndef _BODY_HOME_H_
#define _BODY_HOME_H_
#include "pages/body/body.h"

#define BODY_LOGIN_ID "login"

class body_login : public body
{
private:

public:

	virtual Wt::WWidget* content(std::vector<std::string>& lpath);
	body_login(database* data);
	~body_login();
	
};
#endif