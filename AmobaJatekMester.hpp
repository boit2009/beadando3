#ifndef AMOBAJATEKMESTER_HPP_INCLUDED
#define AMOBAJATEKMESTER_HPP_INCLUDED
#include "graphics.hpp"
#include<string>
#include <vector>
#include "widgets.hpp"
using namespace std;


class AmobaJatekMester
{
protected:

	vector<Widget*> widgets;
	string _ki_jon;
	int _mennyi_lepes_tortent;
    bool _van_e_nyertes;
    bool start;

public:
    AmobaJatekMester();
	void event_loop();
	void lepes_tortent();
	string getkijon();

};



#endif // AMOBAJATEKMESTER_HPP_INCLUDED
