#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include <string>

class Widget
{
protected:
	int _x, _y, _size_x, _size_y;
	bool _focused;
	bool _is_focusable;

public:
	Widget(int x, int y, int sx, int sy);

	virtual bool is_selected(int mouse_x, int mouse_y);
	virtual void draw() = 0;
	virtual void handle(genv::event ev) = 0;
	virtual bool is_focused();
	virtual bool _focusable();



};



#endif // WIDGETS_HPP_INCLUDED
