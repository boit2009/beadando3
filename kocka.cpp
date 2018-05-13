#include "kocka.h"
#include "AmobaJatekMester.hpp"
#include "graphics.hpp"
using namespace genv;


kocka::kocka(int x, int y, int sx, int sy, AmobaJatekMester* parent): Widget(x,y,sx,sy)
{

	_parent=parent;
	_kie="Senki";
	_is_focusable=true;
	_lenyomott=false;

}

void kocka::draw()
{
	if (_kie=="Senki") {
		gout << move_to(_x, _y) << color(23,55,25) << box(_size_x, _size_y);
		gout << move_to(_x+1, _y+1) << color(0,0,0) << box(_size_x-2, _size_y-2);
	}
	if (_kie=="Player 1") {
		gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
		gout << move_to(_x+1, _y+1) << color(255,0,0) << box(_size_x-2, _size_y-2);
	}
	if (_kie=="Player 2") {
		gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
		gout << move_to(_x+1, _y+1) << color(0,0,255) << box(_size_x-2, _size_y-2);
	}

}
void kocka::handle(genv::event ev)
{

	if(!_lenyomott) {
		_kie=_parent->getkijon();
		_is_focusable=false;
		_parent->lepes_tortent();
		_focused=false;
		_lenyomott=true;
	}
}

string kocka::getszoveg()
{
	return _kie;
}

