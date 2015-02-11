//Copyright Michael Pollind 2014


#ifndef	_DOCUMENT_PAIR_H
#define	_DOCUMENT_PAIR_H
#include <string>

class document_pair
{
public:
	
	~document_pair(){};
	virtual std::string get_key() = 0;
	virtual std::string get_value() =0;	
};
#endif