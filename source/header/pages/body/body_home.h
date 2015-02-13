#ifndef _BODY_HOME_H_
#define _BODY_HOME_H_
#include "pages/body/body.h"

#define BODY_HOME_ID "home"

class body_home : public body
{
private:

public:

	virtual Wt::WWidget* content(std::vector<std::string>& lpath);
	body_home(database* data);
	~body_home();
	
};
#endif