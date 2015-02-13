#include "database/database.h"

#include "config.h"

#include "database/image_data.h"
#include "database/book_data.h"
#include "database/chapter_data.h"
#include "database/patch_data.h"
#include "database/review_data.h"

database::database()
{
	_session = new dbo::Session();

	#if DATABASE_TYPE == DATABASE_MYSQL
		_my_sql = new dbo::backend::MySQL(DATABASE_NAME,DATABASE_USERNAME,DATABASE_PASSWORD,DATABASE_HOST,0,DATABASE_SOCKET,-1);
		_session->setConnection(*_my_sql);
	#elif DATABASE_TYPE == DATABASE_SQLITE

	#endif

	_session->mapClass<book_data>(BOOK_DATABASE_ID);
	_session->mapClass<image_data>(IMAGE_DATABASE_ID);
	_session->mapClass<chapter_data>(CHAPTER_DATABASE_ID);
	_session->mapClass<patch_data>(PATCH_DATABASE_ID);
	_session->mapClass<review_data>(REVIEW_DATABASE_ID);

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
