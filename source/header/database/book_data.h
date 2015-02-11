#ifndef	_BOOK_DATA_H_
#define	_BOOK_DATA_H_
#include <string>

#include <string>
#include <Wt/Dbo/Dbo>

namespace dbo = Wt::Dbo;
class book_data
{

private:
	std::string name;
	int upvotes;
	int downvotes;
public:
	book_data();
	~book_data();

	template<class Action>
    void persist(Action& a)
    {

    }
	
};

#endif