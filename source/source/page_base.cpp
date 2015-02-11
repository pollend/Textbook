#include "pages/page_base.h"
#include "config.h"
#include <Wt/WLineEdit>
#include <Wt/WMenu>
#include <Wt/WMessageBox>
#include <Wt/WNavigationBar>
#include <Wt/WPopupMenu>
#include <Wt/WPopupMenuItem>
#include <Wt/WStackedWidget>
#include <Wt/WText>
#include <Wt/WBootstrapTheme>
#include <Wt/WMessageResourceBundle>
#include <Wt/WString>
#include <Wt/WTemplate>
#include <Wt/WAnchor>
#include <Wt/WContainerWidget>
#include <Wt/WLink>


#include <vector> 

#include "database/database.h"

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/classification.hpp>


#include "pages/body/body_not_found.h"
#include "pages/body/body.h"

#include <iostream>

page_base::page_base(const Wt::WEnvironment& env)
: Wt::WApplication(env)
{
	_body = NULL;

	_database = new database();
	

	useStyleSheet("public/style.css");
	useStyleSheet("public/imageoverlay.css");
	require("bower_components/jquery/dist/jquery.min.js");
	require ("public/preview.js");

	//set the theme to use bootstrap 3
	Wt::WBootstrapTheme* ltheme = new Wt::WBootstrapTheme();
	ltheme->setVersion(Wt::WBootstrapTheme::Version::Version3);
	setTheme(ltheme);

	// create main containers
	_head_container = new Wt::WContainerWidget();
	_body_container = new Wt::WContainerWidget();
	_footer_container = new Wt::WContainerWidget();

	_body_container->addStyleClass("center-block");
	_body_container->addStyleClass("main-content");

	_footer_container->addStyleClass("center-block");

	// creates the footer and header
	Wt::WWidget* lhead = head_content();
	Wt::WWidget* lfooter = footer_content();

	root()->addWidget(new Wt::WText(IMAGE_VIEWER,Wt::XHTMLUnsafeText));

	if(lhead != NULL)
		_head_container->addWidget(lhead);
	if(lfooter != NULL)
		_footer_container->addWidget(lfooter);

	root()->addWidget(_head_container);
	root()->addWidget(_body_container);
	root()->addWidget(_footer_container);

	internalPathChanged().connect(std::bind([=] () {
    	 handle_path_change();
	}));
	handle_path_change();

} 

page_base::~page_base()
{
	delete_body();
	delete _database;
}

bool page_base::delete_body()
{
	if(_body != NULL)
	{
		delete _body;
		_body = NULL;
		return true;
	}
	return false;
}

void page_base::handle_path_change()
{
		delete_body();
		
		std::vector<std::string> lsplit;
		std::string lpath = internalPath().substr(1);
		boost::split(lsplit,lpath,boost::is_any_of("/"));

		/*if(lsplit[0]== BODY_ABOUT_ID)
		{
			_menu->select(1);
			_body = new body_about(_database);
		}
		else if(lsplit[0]== BODY_AIRPORT_ID)
		{
			_menu->select(2);
			_body = new body_airport(_database);

		}
		else if(lsplit[0]== BODY_CLUB_ID)
		{
			_menu->select(3);
			_body = new body_club(_database);
		}
		else if(lsplit[0]== BODY_EVENT_ID)	
		{
			_menu->select(4);
			_body = new body_event(_database);
		}
		else if(lsplit[0]== BODY_FEATURES_ID)
		{
			_menu->select(5);
				_body = new body_features(_database);
		}
		else if(lsplit[0]== BODY_LEARN_TO_FLY_ID)
		{
			_menu->select(6);
			_body = new body_learn_to_fly(_database);
		}
		else if (lsplit[0]== BODY_HOME_ID || lsplit[0]== "")
		{
			_menu->select(0);
			_body = new body_home(_database);
		}
		else
		{*/
			_body = new body_not_found(_database);
		//}

		_body_container->clear();
		Wt::WWidget* lbody = _body->content(lsplit);

		if(lbody == NULL)
		{
			delete_body();
			_body = new body_not_found(_database);
			lbody = _body->content(lsplit);
		}

		_body_container->addWidget(lbody);
}

Wt::WWidget* page_base::head_content()
{
Wt::WContainerWidget *container = new Wt::WContainerWidget();


// Create a navigation bar with a link to a web page.
Wt::WNavigationBar *navigation = new Wt::WNavigationBar(container);
navigation->setTitle("Pilotage",
		     "http://www.google.com/search?q=corpy+inc");
navigation->setResponsive(true);

Wt::WStackedWidget *contentsStack = new Wt::WStackedWidget(container);
contentsStack->addStyleClass("contents");

// Setup a Left-aligned menu.
_menu= new Wt::WMenu(contentsStack, container);
navigation->addMenu(_menu);

_menu->addItem("Home")->setLink(Wt::WLink(Wt::WLink::InternalPath, "/home"));
_menu->addItem("About")->setLink(Wt::WLink(Wt::WLink::InternalPath, "/about"));
_menu->addItem("Airports")->setLink(Wt::WLink(Wt::WLink::InternalPath, "/airport"));
_menu->addItem("Clubs")->setLink(Wt::WLink(Wt::WLink::InternalPath, "/clubs"));
_menu->addItem("Events")->setLink(Wt::WLink(Wt::WLink::InternalPath, "/events"));
_menu->addItem("Features")->setLink(Wt::WLink(Wt::WLink::InternalPath, "/features"));
_menu->addItem("Learn To Fly")->setLink(Wt::WLink(Wt::WLink::InternalPath, "/learn_to_fly"));

// Setup a Right-aligned menu.
Wt::WMenu *rightMenu = new Wt::WMenu();
navigation->addMenu(rightMenu, Wt::AlignRight);

// Add a Search control.
Wt::WLineEdit *edit = new Wt::WLineEdit();
edit->setEmptyText("Enter a search item");

edit->enterPressed().connect(std::bind([=] () {
    _menu->select(2); // is the index of the "Sales"
}));

navigation->addSearch(edit, Wt::AlignRight);

container->addWidget(contentsStack);
	return container;
}

Wt::WWidget* page_base::body_content()
{
	return NULL;
}

Wt::WWidget* page_base::footer_content()
{
	Wt::WContainerWidget* lfooter =  new Wt::WContainerWidget();
	lfooter->addStyleClass("footer");

	Wt::WContainerWidget* lmain_blurb =  new Wt::WContainerWidget();
	lmain_blurb->addStyleClass("sponser");
	new Wt::WText("PilotAge homepage is sponsored by <a href='http://www.dcgfx.com/'>Digital Choreographics</a>",lmain_blurb);

	Wt::WContainerWidget* lmain_copy_right =  new Wt::WContainerWidget();
	lmain_copy_right->addStyleClass("copyright");
	new Wt::WText("<div>PilotAge is a trademark of Digital ChoreoGraphics</div>",lmain_copy_right);
	new Wt::WText("<div>Copyright &copy;1997-2001, Digital ChoreoGraphics</div>",lmain_copy_right);

	lfooter->addWidget(lmain_blurb);
	lfooter->addWidget(lmain_copy_right);

	return lfooter;
}

