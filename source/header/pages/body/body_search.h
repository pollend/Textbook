#ifndef _BODY_SEARCH_H_
#define _BODY_SEARCH_H_
#include "pages/body/body.h"

class body_explore : public body
{
	private:

	public:

		virtual Wt::WWidget* content(std::vector<std::string>& lpath);
		body_explore(database* data);
		~body_explore();
	
};
#endif
