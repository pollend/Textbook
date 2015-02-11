//Copyright Michael Pollind 2014


#ifndef	_BASIC_DOCUMENT_PAIR_H
#define	_BASIC_DOCUMENT_PAIR_H
#include <string>
#include "document/document_pair.h"

class basic_document_pair : public document_pair
{
private:
	std::string _key;
	std::string _value;
public:

	basic_document_pair(std::string key, std::string value);
	~basic_document_pair();
	virtual std::string get_key();
	virtual std::string get_value();	
};
#endif