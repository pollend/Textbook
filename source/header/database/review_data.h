#ifndef	_REVIEW_DATA_H_
#define	_REVIEW_DATA_H_
#include <string>

#include <string>
#include <Wt/Dbo/Dbo>

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