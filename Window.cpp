
#include "Window.hpp"
using namespace genv;




void Window::event_loop()
{

	event ev;
	int focus = -1;
	while(gin >> ev ) {
		if (ev.type==ev_key && ev.keycode==key_escape)
			break;

		if (this->start(ev, focus)) {
			if (ev.type == ev_mouse && ev.button==btn_left) {
				for (unsigned int i=0; i<widgets.size(); i++) {
					if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)|| widgets[i]->is_focused() && widgets[i]->_focusable()) {
						if (focus!=-1) {
							widgets[focus]->handle(ev);
						}
						if(focus!=-1) {
							if(!widgets[focus]->is_focused())
								focus = i;
						} else {
							focus = i;
						}
					}
				}

			}
			if (focus!=-1) {
				widgets[focus]->handle(ev);
				widgets[focus]->draw();

			}
			bool osszes_nem_focused=true;
			for (unsigned int i=0; i<widgets.size(); i++) {
				if(widgets[i]->is_focused()) {
					osszes_nem_focused=false;
				}
			}
			if(osszes_nem_focused)
				for (Widget * w : widgets) {
					w->draw();
				}

			gout << refresh;

		}
	}
	for (unsigned int i=0; i<widgets.size(); i++)
		delete widgets[i];
}


