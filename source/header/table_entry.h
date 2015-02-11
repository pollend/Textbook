#ifndef	_TABLE_ENTRY_H
#define	_TABLE_ENTRY_H

#include <string>
#include <map>

#include "parser_type.h"
class table_entry{
	friend class table;
	private:
		std::map<std::string, std::string> _key_values;
		void add_entry(std::string key, std::string value);
		parser_type _type;
		table_entry(parser_type type);

		std::string utf_decode(const std::string & sSrc);
		std::string utf_encode(const std::string & sSrc);


	public:
		~table_entry();
		
		std::string get_entry(std::string key);
		void set_entry(std::string key, std::string value);

};
#endif