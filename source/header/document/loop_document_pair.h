//Copyright Michael Pollind 2014

#ifndef	_LOOP_DOCUMENT_PAIR_H
#define	_LOOP_DOCUMENT_PAIR_H
#include <string>
#include <vector>
#include "document/document_pair.h"
class basic_document_pair;
class loop_document_pair : public document_pair
{
private:
	std::string _key;
	std::string _value;
	std::vector<std::vector<basic_document_pair*> > _pairs;
public:
	loop_document_pair(std::string key, std::string value);
	~loop_document_pair();

	void add_looped_pair(std::vector<basic_document_pair*> document_pair);

	virtual std::string get_key();
	virtual std::string get_value();		
};

#endif