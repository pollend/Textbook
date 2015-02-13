#include "database/chapter_data.h"

chapter_data::chapter_data()
{
	
}
chapter_data::~chapter_data()
{
	
}
void chapter_data::set_chapter_title(std::string title)
{
	_chapter_title = title;
}
const std::string chapter_data::get_chapter_title()
{
	return _chapter_title;
}

const std::string chapter_data::get_text()
{
	return _text;
}

void chapter_data::set_text(std::string text)
{
	_text = text;
}

