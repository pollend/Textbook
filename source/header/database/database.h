#ifndef _DATABASE_H
#define	_DATABASE_H

#include <Wt/Dbo/Dbo>
#include "config.h"

#define AIRPORTS "airport"
#define BUSINESS "business"


#if DATABASE_TYPE == DATABASE_MYSQL
#include <Wt/Dbo/backend/MySQL>
#elif DATABASE_TYPE == DATABASE_SQLITE
#include <Wt/Dbo/backend/Sqlite3>
#endif

namespace dbo = Wt::Dbo;

class business_data;
class airport_data;
class database
{
	private:
		#if DATABASE_TYPE == DATABASE_MYSQL
			dbo::backend::MySQL* _my_sql;
		#elif DATABASE_TYPE == DATABASE_SQLITE
		#endif

		dbo::Session* _session;
	public:
		database();
		~database();

		dbo::Session* get_session();

};

#endif