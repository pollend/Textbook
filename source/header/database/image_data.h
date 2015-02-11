#ifndef	_IMAGE_DATA_H
#define	_IMAGE_DATA_H
#include <string>

class image_data
{
private:
	std::string _image_key;

public:
	int add_legacy_image(std::string directory);

	image_data();
	~image_data();
	
};

#endif