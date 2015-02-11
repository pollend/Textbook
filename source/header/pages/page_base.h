
#ifndef	_BASE_PAGE_H
#define	_BASE_PAGE_H

#define IMAGE_VIEWER "<div id=\"overlay-backdrop\"></div> \
<div id=\"overlay-enlarged-image-container\"> \
	<div id=\"overlay-image\"> \
		<img id=\"image-overlay-image\"></img> \
		<div id=\"image-over-loading\"></div> \
		<a id=\"image-overlay-close\" href=\"#\"> \
			<div class=\"overlay-controls\"></div> \
		</a> \
		<div id=\"image-overlay-caption\" class=\"overlay-controls\"> \
			<div class=\"num-images\"></div> \
			<div class=\"image-caption\"></div> \
		</div> \
		<a href=\"#\" id=\"image-overlay-left\"> \
			<div class=\"click-area\"></div> \
			<div class=\"button\" class=\"overlay-controls\"></div> \
		</a> \
		<a href=\"#\" id=\"image-overlay-right\"> \
			<div class=\"click-area\"></div> \
			<div class=\"button\" class=\"overlay-controls\"></div> \
		</a> \
	</div> \
</div>"

#include <Wt/WApplication>
#include <Wt/WContainerWidget>

class body;
class database;
class WMenu;
class page_base : public Wt::WApplication
{
private:
	body* _body;

	Wt::WMenu *_menu;

	Wt::WContainerWidget* _head_container;
	Wt::WContainerWidget* _body_container;
	Wt::WContainerWidget* _footer_container;
	database * _database;

	bool delete_body();
public:

	Wt::WWidget* head_content();
	Wt::WWidget* body_content();
	Wt::WWidget* footer_content(); 

	void handle_path_change();

	void init();
	page_base(const Wt::WEnvironment& env);
	~page_base();
	
};


#endif