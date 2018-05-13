#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED
#include "graphics.hpp"
#include<string>
#include <vector>
#include "widgets.hpp"
using namespace std;


class Window
{
protected:

	vector<Widget*> widgets;

public:
	virtual bool start(genv::event ev, int &focus)=0;
	void event_loop();
};



#endif // WINDOW_HPP_INCLUDED
