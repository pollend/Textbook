#include "config.h"
#include <iostream>
#include <exception>
#include "database/database.h"

#include <boost/regex.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/trim.hpp>

#include <Wt/Dbo/Dbo>

namespace dbo = Wt::Dbo;
int main(int argc, char *argv[])
{
	if(argc >= 2)
	{
		database ldata = database();
		try{
			ldata.get_session()->createTables();
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << "\n";
		}
		
	
	}
	else
	{
	}
}