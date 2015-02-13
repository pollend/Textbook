#ifndef _BODY_NOT_FOUND_H_
#define _BODY_NOT_FOUND_H_
#include "pages/body/body.h"

#define BODY_EXPLORE_ID "explore"

class body_explore : public body
{
private:

public:

	virtual Wt::WWidget* content(std::vector<std::string>& lpath);
	body_explore(database* data);
	~body_explore();
	
};
#endif
