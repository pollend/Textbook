#ifndef _BODY_SEARCH_H_
#define _BODY_SEARCH_H_
#include "pages/body/body.h"

class body_search : public body
{
	private:

	public:

		virtual Wt::WWidget* content(std::vector<std::string>& lpath);
		body_search(database* data);
		~body_search();
	
};
#endif
