#include "database/database.h"

#include "database/airport_data.h"
#include "database/business_data.h"
#include "config.h"

database::database()
{
	_session = new dbo::Session();

	#if DATABASE_TYPE == DATABASE_MYSQL
		_my_sql = new dbo::backend::MySQL(DATABASE_NAME,DATABASE_USERNAME,DATABASE_PASSWORD,DATABASE_HOST,0,"/var/run/mysqld/mysqld.sock",-1);
		_session->setConnection(*_my_sql);
	#elif DATABASE_TYPE == DATABASE_SQLITE

	#endif

	_session->mapClass<airport_data>(AIRPORTS);
	_session->mapClass<business_data>(BUSINESS);
}
database::~database()
{
	delete _my_sql;
	delete _session;
}

dbo::Session* database::get_session()
{
	return _session;
}
