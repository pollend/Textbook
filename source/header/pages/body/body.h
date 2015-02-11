#ifndef _BODY_H_
#define _BODY_H_ 
#include <Wt/WApplication>
#include <vector>

class database;
class body
{
	protected:
		database * _database;
	public:
		virtual Wt::WWidget* content(std::vector<std::string>& lpath) =0;
		
		body(database* data);
		~body();
	
};

#endif