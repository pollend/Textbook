//Copyright Michael Pollind 2014


#ifndef	_DOCUMENT_H
#define	_DOCUMENT_H

#include "document/document_pair.h"
#include <string>
#include <vector>

class document
{
	private:

		std::string _document; 
		std::vector<document_pair*> _pairs;

		std::string utf_decode(const std::string & sSrc);

	public:
		~document();

		/**
		*load up the document from the filesystem
		**/
		document(std::string directory);

		/**
		*retrieves the document pair
		**/
		document_pair* get_document_pair(std::string key);

		/**
		*set a key value pair to be attached to the document
		**/
		void set_value(std::string key, std::string value);
		
		/**
		*set a value but append the document to the file instead
		**/
		void set_value(std::string key, document* doc);

		/**
		*write the doucment out to the filesystem as an html file
		**/		
		void write_document_out(std::string file);

		/**
		*process the document and return as a string
		**/
		std::string get_document();
};

#endif