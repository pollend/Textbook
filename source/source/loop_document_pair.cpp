
#include "document/loop_document_pair.h"
#include "document/basic_document_pair.h"
#include <boost/regex.hpp>

loop_document_pair::loop_document_pair(std::string key, std::string value)
{
	_key = key;
	_value = value;
	_pairs = std::vector<std::vector<basic_document_pair*> >();
}

loop_document_pair::~loop_document_pair()
{
	for(std::vector<std::vector<basic_document_pair*> >::iterator it = _pairs.begin();it != _pairs.end();++it)
	{

		for(std::vector<basic_document_pair*>::iterator xt = (*it).begin();xt != (*it).end();++xt)
		{
			delete (*xt);
		}
	}
}

void loop_document_pair::add_looped_pair(std::vector<basic_document_pair*> document_pairs)
{
	_pairs.push_back(document_pairs);
}


std::string loop_document_pair::get_key()
{
	return _key;
}

std::string loop_document_pair::get_value()
{
	std::string loutput = std::string();

	for(std::vector<std::vector<basic_document_pair*> >::iterator it = _pairs.begin();it != _pairs.end();++it)
	{
		std::string lblock = std::string(_value);
		for(std::vector<basic_document_pair*>::iterator xt = (*it).begin();xt != (*it).end();++xt)
		{
			boost::regex expression(":" + 	(*xt)->get_key() + ":");
			lblock = boost::regex_replace(lblock,expression,(*xt)->get_value());
		}
		loutput += lblock;
	}
	return loutput;
}	