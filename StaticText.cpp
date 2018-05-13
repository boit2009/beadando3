#include "StaticText.hpp"
#include "graphics.hpp"
using namespace genv;

StaticText::StaticText(int x, int y, int sx, int sy,string sz)
	: Widget(x,y,sx,sy)
{

	_focused=false;
	_szoveg=sz;
}

void StaticText::draw()
{
	string ideiglenes="";
	if(gout.twidth(_szoveg)+15>_size_x) {

		int mettol=(gout.twidth(_szoveg)-_size_x)/8;
		for (unsigned int i=mettol+5; i<_szoveg.length(); i++) {
			ideiglenes+=_szoveg[i];

		}
	} else {
		for (unsigned int i=0; i<_szoveg.length(); i++) {
			ideiglenes+=_szoveg[i];
		}
	}
	gout << move_to(_x, _y) << color(32,55,122) << box(_size_x, _size_y);
	gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
	gout<<move_to(_x+_size_x/2-gout.twidth(ideiglenes)/2,_y+_size_y/2+(gout.cascent()+gout.cdescent())/2)<<color(21,243,255)<<text(ideiglenes);


	gout << color(255,255,255);



}

void StaticText::handle(event ev)
{

}
bool StaticText::is_focused()
{
	return false;
}
bool StaticText::_focusable()
{
	return false;
}
void StaticText::setfocused()
{

}
void StaticText::settext(string txt)
{
	_szoveg=txt;
}
string StaticText::gettext()
{
	return _szoveg;
}
