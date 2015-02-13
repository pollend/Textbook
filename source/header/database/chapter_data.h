#ifndef	_CHAPTER_DATA_H_
#define	_CHAPTER_DATA_H_
#include <string>
#include <Wt/Dbo/Dbo>

#include "database/patch_data.h"
#include "database/book_data.h"
#include "database/image_data.h"

#define CHAPTER_DATABASE_ID "chapter"

namespace dbo = Wt::Dbo;
class book_data;
class image_data;
class patch_data;
class chapter_data
{

private:
	dbo::collection<dbo::ptr<patch_data>> _patches;
	dbo::collection<dbo::ptr<image_data>> _images;

	dbo::ptr<book_data> _book;

	std::string _chapter_title;
	std::string _text;
public:
	chapter_data();
	~chapter_data();

	void set_chapter_title(std::string title);
	const std::string get_chapter_title();

	void set_text(std::string text);
	const std::string get_text();

	template<class Action>
    void persist(Action& a)
    {
    	dbo::belongsTo(a, _book, "book_chapters");

    	dbo::hasMany(a, _patches, dbo::ManyToOne, "chapter_patches");
		dbo::hasMany(a, _images, dbo::ManyToOne, "chapter_image");

		dbo::field(a, _chapter_title, "chapter_title");
		dbo::field(a,_text,"content");
    }
	
};

#endif