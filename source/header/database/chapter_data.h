#ifndef	_CHAPTER_DATA_H_
#define	_CHAPTER_DATA_H_
#include <string>

#include <string>
#include <Wt/Dbo/Dbo>

namespace dbo = Wt::Dbo;
class chapter_data
{

private:
	std::string chapter_title;
	std::string text;
public:
	chapter_data();
	~chapter_data();

	template<class Action>
    void persist(Action& a)
    {

    }
	
};

#endif