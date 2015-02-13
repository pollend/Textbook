#ifndef	_BOOK_DATA_H_
#define	_BOOK_DATA_H_
#include <string>
#include <Wt/Dbo/Dbo>

#include "database/chapter_data.h"
#define BOOK_DATABASE_ID "book"

namespace dbo = Wt::Dbo;
class chapter_data;
class book_data
{

private:
	std::string _name;
	int _up_votes;
	int _down_votes;

	dbo::collection<dbo::ptr<chapter_data> > _chapters;
public:
	book_data();
	~book_data();

	template<class Action>
    void persist(Action& a)
    {
    	dbo::hasMany(a, _chapters, dbo::ManyToOne, "book_chapters");

    	dbo::field(a,_up_votes,"up_votes");
    	dbo::field(a,_down_votes,"down_votes");
    	dbo::field(a,_name,"name");
    }
	
};

#endif