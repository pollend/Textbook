#include "document/document.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <boost/filesystem/fstream.hpp>
#include "config.h"
#include <stdio.h>
#include "document/basic_document_pair.h"
#include "document/document_pair.h"
#include "document/loop_document_pair.h"

document::document(std::string directory)
{
	boost::filesystem::path lpath(directory + ".template");

	_pairs = std::vector<document_pair*>();
	std::ifstream lfile(lpath.string().c_str());

	if(lfile.is_open())
	{
		std::string lline;
		while(std::getline(lfile,lline))
		{
			boost::trim(lline);	
			char lbegin = ' ';
			if(lline.length() >= 1)
				lbegin = lline[0];

			if(lbegin == '#')
			{
				std::vector<std::string> lsplit = std::vector<std::string>();
				boost::split(lsplit,lline,boost::is_any_of(" "));
				
				try {
					//appended a document as a key value pair
					if(lsplit[0] == "#document" && lsplit[2] == "as")
					{
						//create a document and append it to a key value pair
						document* ldoc = new document((lpath.parent_path().string() + "/"+lsplit[1]).c_str());
						set_value(lsplit[3].c_str(),ldoc);
						delete ldoc;
					}
				
					if(lsplit[0] == "#set" && lsplit[2] == "as")
					{
						//create a document and append it to a key value pair
						set_value(lsplit[1].c_str(),lsplit[3].c_str());
					}
				
					if(lsplit[0] == "#loop")
					{
						std::string lloop_value =std::string();
						while(std::getline(lfile,lline))
						{
							if(lline == "#endfor")
								break;
							lloop_value += lline;
						}

						_pairs.push_back(new loop_document_pair(lsplit[1],lloop_value));
					}
				}
				catch (std::out_of_range& err) {
					printf("incorect syntax for template:%s\n for lline %s \n",lpath.string().c_str(), lline.c_str());
				}
			}
			else if(lbegin == '/')
			{
				//comments are skipped by the parser
			}
			else
			{
				_document += lline + "\n";
			}	

		} 
	}
	else
	{
		printf("%s:%s\n","could not find file" ,lpath.string().c_str() );
	}
	lfile.close();
	set_value("ROOT",DIR_ROOT);
	set_value("DNS_ROOT",DNS_ROOT);

}
document::~document()
{
	for(std::vector<document_pair*>::iterator it = _pairs.begin();it != _pairs.end();++it)
	{
		delete (*it);
	}
}

//sets the value in the document
void document::set_value(std::string key, std::string value)
{
	_pairs.push_back(new basic_document_pair(key,value));
	
}

//apppend another document to the current one
void document::set_value(std::string key, document* doc)
{
	_pairs.push_back(new basic_document_pair(key,doc->get_document()));
}

document_pair* document::get_document_pair(std::string key)
{
	for(std::vector<document_pair*>::iterator it = _pairs.begin();it != _pairs.end();++it)
	{
		if((*it)->get_key() == key)
		{
			return (*it);
			break;
		}
	}
	return NULL;
}


std::string document::get_document()
{
	std::string out = _document;
	for(std::vector<document_pair*>::iterator it = _pairs.begin();it != _pairs.end();++it)
	{
		boost::regex expression("\\:" + 	(*it)->get_key() + "\\:");
		out = boost::regex_replace(out,expression,(*it)->get_value());
	}

	return out;
}


void document::write_document_out(std::string file)
{
	boost::filesystem::path lfile(file + ".html");
	
	if(boost::filesystem::exists(lfile))
		boost::filesystem::remove(lfile);

	std::ofstream louput_file(lfile.string().c_str());
	if(!louput_file.is_open())
	{
		printf("can't save file:%s\n", file.c_str());
	}
	else
	{
		//printf("%s\n",get_document().c_str() );
		louput_file <<  get_document();
	}
	louput_file.close();
}

