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
    virtual void esemeny(genv::event ev)=0;
	void event_loop();
};



#endif // WINDOW_HPP_INCLUDED
