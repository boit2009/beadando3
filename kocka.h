#ifndef KOCKA_H_INCLUDED
#define KOCKA_H_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"
#include "AmobaJatekMester.hpp"


class AmobaJatekMester;
class kocka : public Widget
{
protected:

	string _kie;
	bool _lenyomott;
	AmobaJatekMester* _parent;
	int _sorszam;



public:
	kocka(int x, int y, int sx, int sy,int sorszam, AmobaJatekMester* parent);

	void draw();
	void handle(genv::event ev);
	string getszoveg();




};



#endif // KOCKA_H_INCLUDED
