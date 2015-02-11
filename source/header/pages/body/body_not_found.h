#ifndef _BODY_NOT_FOUND_H_
#define _BODY_NOT_FOUND_H_
#include "pages/body/body.h"
class body_not_found : public body
{
private:

public:

	virtual Wt::WWidget* content(std::vector<std::string>& lpath);

	body_not_found(database* data);
	~body_not_found();
	
};

#endif