#include "document/basic_document_pair.h"
	
basic_document_pair::basic_document_pair(std::string key, std::string value) 
{
	_key = key;
	_value = value;
}

basic_document_pair::~basic_document_pair()
{

}

std::string basic_document_pair::get_key()
{
	return _key;
}

std::string basic_document_pair::get_value()
{
	return _value;
}	