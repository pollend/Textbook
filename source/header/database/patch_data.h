#ifndef	_PATCH_DATA_H_
#define	_PATCH_DATA_H_
#include <string>
#include <Wt/Dbo/Dbo>

#include "database/image_data.h"
#include "database/chapter_data.h"

#define PATCH_DATABASE_ID "patch"

namespace dbo = Wt::Dbo;
class image_data;
class chapter_data;
class patch_data : public dbo::Dbo<patch_data> 
{
public:
	enum patch_state
	{
		close = 1,
		open = 2,
		conflict = 3
		
	};
private:
	//noifys that the modification is conflicting
	bool _modification_conflict;

	//where the modification starts
	int _beginning;

	//where the modification ends
	int end;

  	dbo::collection< dbo::ptr<image_data> > _images;
  	dbo::ptr<chapter_data> _chapter;

	std::string diff;
public:
	patch_data();
	~patch_data();

	/*
	*submits the modification to the text and calulates the offset for all modifications that proceede this one
	*also notify other modifications for conflicts
	*/
	void submit_modification();
	void offset_modification_position(int offset);

	template<class Action>
    void persist(Action& a)
    {

 		dbo::belongsTo(a, _chapter, "chapter_patches");
 		dbo::hasMany(a, _images, dbo::ManyToOne, "patch_image");
    }
	
};

#endif