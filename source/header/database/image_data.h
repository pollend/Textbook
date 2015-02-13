#ifndef	_IMAGE_DATA_H
#define	_IMAGE_DATA_H
#include <string>
#include <Wt/Dbo/Dbo>

#include "database/patch_data.h"
#include "database/chapter_data.h"

#define IMAGE_DATABASE_ID "image"

namespace dbo = Wt::Dbo;
class patch_data;
class chapter_data;
class image_data
{
private:
	std::string _description;
	dbo::ptr<chapter_data> _chapter;
	dbo::ptr<patch_data> _patch;

public:
	void add_image();
	image_data();
	~image_data();

	template<class Action>
    void persist(Action& a)
    {
    	dbo::belongsTo(a, _chapter, "chapter_image");
    	dbo::belongsTo(a, _patch, "patch_image");

		dbo::field(a,_description,"description");
    }
	
};

#endif