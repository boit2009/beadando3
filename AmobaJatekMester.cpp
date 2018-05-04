#include "AmobaJatekMester.hpp"
#include <iostream>
#include "graphics.hpp"
#include "StaticText.hpp"
#include "kocka.h"
using namespace genv;
void nyeresvizsgalat(int szamlalo, string& idg, string& kijon, bool& vanenyertes,bool& startos)
{
	if (szamlalo==4) {
		idg=kijon;
		idg+=" NYERT! Új Játék: s ";
		vanenyertes=true;
		startos=false;
	}
}


StaticText *w= new StaticText(200,60,300,50,"Player 1 következik");
StaticText *p1= new StaticText(30,60,100,50,"P1: piros");
StaticText *p2= new StaticText(570,60,100,50,"P2: kék");


AmobaJatekMester::AmobaJatekMester()
{
	widgets.push_back(w);
	widgets.push_back(p1);
	widgets.push_back(p2);
	_ki_jon="Player 1";
	_van_e_nyertes=false;
	start=true;

	_mennyi_lepes_tortent=0;
	for (int i=0; i<20; i++) {
		for(int j=0; j<20; j++) {
			kocka  *uj=new kocka(150+j*20,150+i*20,20,20,i*10+j,this);
			widgets.push_back(uj);
		}
	}

}
void AmobaJatekMester::lepes_tortent()
{
	_mennyi_lepes_tortent++;
	string ideiglenes="";

	int sorbaszamolo=0;
	for (unsigned int i=3; i<widgets.size(); i++) {

		if(widgets[i]->getszoveg()!="Senki") {
			if((i-3)%20+4<20 && i<399) {
				for(unsigned int j=i+1; j<i+5; j++) {
					if(widgets[i]->getszoveg()==widgets[j]->getszoveg())
						sorbaszamolo++;
					else
						break;
				}
			}
			nyeresvizsgalat(sorbaszamolo,ideiglenes,_ki_jon,_van_e_nyertes,start);

//                if (sorbaszamolo==4)
//                {
//                    ideiglenes=_ki_jon;
//                    ideiglenes+=" NYERT!";
//                    _van_e_nyertes=true;
//                }
			sorbaszamolo=0;

			if(i-3+80<400) {

				for(unsigned int j=i+20; j<i+100; j=j+20) {
					if(widgets[i]->getszoveg()==widgets[j]->getszoveg())
						sorbaszamolo++;
					else
						break;

				}
			}
			nyeresvizsgalat(sorbaszamolo,ideiglenes,_ki_jon,_van_e_nyertes,start);
			sorbaszamolo=0;

			if(i-3+84<400 && ((i-3)%20+4<20)) {
				for(unsigned int j=i+21; j<i+105; j=j+21) {
					if(widgets[i]->getszoveg()==widgets[j]->getszoveg())
						sorbaszamolo++;
					else
						break;

				}
			}
			nyeresvizsgalat(sorbaszamolo,ideiglenes,_ki_jon,_van_e_nyertes,start);
			sorbaszamolo=0;

			if(i-3+76<400 && ((i-3)%20>3)) {
				for(unsigned int j=i+19; j<i+95; j=j+19) {
					if(widgets[i]->getszoveg()==widgets[j]->getszoveg())
						sorbaszamolo++;
					else
						break;

				}
			}
			nyeresvizsgalat(sorbaszamolo,ideiglenes,_ki_jon,_van_e_nyertes,start);
			sorbaszamolo=0;

		}
	}


	if(_mennyi_lepes_tortent==400) {
		ideiglenes="PATT, NINCS TÖBB HELY!";
	} else {
		if(_ki_jon=="Player 1") {
			_ki_jon="Player 2";
		} else
			_ki_jon="Player 1";
		if(!_van_e_nyertes) {
			ideiglenes=_ki_jon;
			ideiglenes+=" következik";
		}
	}
	w->settext(ideiglenes);

}




void AmobaJatekMester::event_loop()
{
	event ev;
	int focus = -1;
	while(gin >> ev ) {
		if (ev.type==ev_key && ev.keycode==key_escape)
			break;
		if(ev.keycode==115) {
			focus=-1;
			start=true;
			for (unsigned int i=3; i<widgets.size(); i++) {
				delete widgets[i];
			}
			widgets.resize(3);
			_ki_jon="Player 1";
			_van_e_nyertes=false;
            w->settext("Player 1 következik");
			_mennyi_lepes_tortent=0;
			for (int i=0; i<20; i++) {
				for(int j=0; j<20; j++) {
					kocka  *uj=new kocka(150+j*20,150+i*20,20,20,i*10+j,this);
					widgets.push_back(uj);
				}
			}
		}
		if (start) {
			if (ev.type == ev_mouse && ev.button==btn_left) {
				for (unsigned int i=3; i<widgets.size(); i++) {
					if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)|| widgets[i]->is_focused()) {
						if (focus!=-1) {
							widgets[focus]->handle(ev);
						}
						if(focus!=-1) {
							if(!widgets[focus]->is_focused())
								focus = i;
						}
						else {
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
			for (unsigned int i=3; i<widgets.size(); i++) {
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
string AmobaJatekMester::getkijon()
{
	return _ki_jon;
}
