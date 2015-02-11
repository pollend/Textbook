#include "pages/body/body_not_found.h"
#include <Wt/WText>


Wt::WWidget* body_not_found::content(std::vector<std::string>& lpath)
{
	return new Wt::WText("404");
}

body_not_found::body_not_found(database * data) : 
body::body(data)
{


}

body_not_found::~body_not_found()
{																																																																																																																																																																	

}
