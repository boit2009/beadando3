#ifndef VBUTTON_HPP_INCLUDED
#define VBUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "PushButton.hpp"
#include "Window.hpp"

class vButton : public PushButton{
protected:
    Window* _parent;


public:
   virtual void action();
   vButton(int x, int y, int sx, int sy, std::string szoveg,Window* parent);

};


#endif // VBUTTON_HPP_INCLUDED
