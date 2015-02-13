#ifndef	_REVIEW_DATA_H_
#define	_REVIEW_DATA_H_
#include <string>
#include <Wt/Dbo/Dbo>

#include "database/patch_data.h"

#define REVIEW_DATABASE_ID "review"

namespace dbo = Wt::Dbo;
class review_data
{
private:

public:
	review_data();
	~review_data();

	template<class Action>
    void persist(Action& a)
    {

    }
	
};

#endif