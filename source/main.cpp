#include "pages/page_base.h"

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{

    return new page_base(env);
}

int main(int argc, char *argv[])
{
	 return Wt::WRun(argc, argv, &createApplication);
}