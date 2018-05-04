#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include<string>
using namespace std;

class StaticText: public Widget {
protected:
    string _szoveg;
  //  bool _focused;
public:
    StaticText(int x, int y, int sx, int sy, string sz);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_focused() ;
    virtual void setfocused();
    virtual bool _focusable();
    void settext(string txt);
    string gettext();
};

#endif // STATICTEXT_HPP_INCLUDED
