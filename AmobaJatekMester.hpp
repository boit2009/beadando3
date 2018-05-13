#ifndef AMOBAJATEKMESTER_HPP_INCLUDED
#define AMOBAJATEKMESTER_HPP_INCLUDED
#include "graphics.hpp"
#include<string>
#include <vector>
#include "widgets.hpp"
#include "StaticText.hpp"
#include "kocka.h"
#include "Window.hpp"
using namespace std;
class kocka;

class AmobaJatekMester : public Window{
protected:
	vector<kocka*> kockak;
	string _ki_jon;
	int _mennyi_lepes_tortent;
    bool _van_e_nyertes;
    bool _start;
    StaticText *w;
    StaticText *p1;
    StaticText *p2;

public:
    AmobaJatekMester();
	void lepes_tortent();
	string getkijon();
    bool start(genv::event ev, int &focus);

};



#endif // AMOBAJATEKMESTER_HPP_INCLUDED
