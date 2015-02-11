#ifndef	_TABLE_H
#define	_TABLE_H

#include <string>
#include <map>
#include <vector>

#include "parser_type.h"

class table_entry;
class table{

	private:
		std::vector<table_entry*>* _entries;
	public:
		/**
		*creates a table object and loads in the necessary table file
		**/
		table(std::string document,parser_type type );
		
		/**
		*deletes the table
		**/
		~table();

		/**
		*get the beggining iterator for all the entiries
		**/
		std::vector<table_entry*>::iterator begin();
		
		/**
		*get the ending iterator for all the entires
		**/
		std::vector<table_entry*>::iterator end();
		
		/**
		**/
		void delete_entry(table_entry* entry);
		
		/**
		**/
		void add_entry(table_entry* entry);
		/**
		**/
		table_entry* get_entry_template();

		/**
		*returns all the entries
		**/
		std::vector<table_entry*>* get_entries();

		std::vector<table_entry*> find_entries(std::string key, std::string value);

};
#endif