#include "AmobaJatekMester.hpp"
#include <iostream>
#include "graphics.hpp"

#include "kocka.h"
using namespace genv;
void nyeresvizsgalat(int szamlalo, string& idg, string& kijon, bool& vanenyertes,bool& startos)
{
	if (szamlalo==4) {
		idg=kijon;
		idg+=" NYERT! �j J�t�k: s ";
		vanenyertes=true;
		startos=false;
	}
}





AmobaJatekMester::AmobaJatekMester()
{
	gout.open(700,700);
	w= new StaticText(200,60,300,50,"Player 1 k�vetkezik");
	p1= new StaticText(30,60,100,50,"P1: piros");
	p2= new StaticText(570,60,100,50,"P2: k�k");
	widgets.push_back(w);
	widgets.push_back(p1);
	widgets.push_back(p2);
	_ki_jon="Player 1";
	_van_e_nyertes=false;
	_start=true;

	_mennyi_lepes_tortent=0;
	for (int i=0; i<20; i++) {
		for(int j=0; j<20; j++) {
			kocka  *uj=new kocka(150+j*20,150+i*20,20,20,this);
			widgets.push_back(uj);
			kockak.push_back(uj);
		}
	}

}
void AmobaJatekMester::lepes_tortent()
{
	_mennyi_lepes_tortent++;
	string ideiglenes="";
	int sorbaszamolo=0;
	for (unsigned int i=0; i<kockak.size(); i++) {

		if(kockak[i]->getszoveg()!="Senki") {
			if((i)%20+4<20 && i<396) {
				for(unsigned int j=i+1; j<i+5; j++) {
					if(kockak[i]->getszoveg()==kockak[j]->getszoveg())
						sorbaszamolo++;
					else
						break;
				}
			}
			nyeresvizsgalat(sorbaszamolo,ideiglenes,_ki_jon,_van_e_nyertes,_start);
			sorbaszamolo=0;

			if(i+80<400) {

				for(unsigned int j=i+20; j<i+100; j=j+20) {
					if(kockak[i]->getszoveg()==kockak[j]->getszoveg())
						sorbaszamolo++;
					else
						break;

				}
			}
			nyeresvizsgalat(sorbaszamolo,ideiglenes,_ki_jon,_van_e_nyertes,_start);
			sorbaszamolo=0;

			if(i+84<400 && ((i)%20+4<20)) {
				for(unsigned int j=i+21; j<i+105; j=j+21) {
					if(kockak[i]->getszoveg()==kockak[j]->getszoveg())
						sorbaszamolo++;
					else
						break;

				}
			}
			nyeresvizsgalat(sorbaszamolo,ideiglenes,_ki_jon,_van_e_nyertes,_start);
			sorbaszamolo=0;

			if(i+76<400 && ((i)%20>3)) {
				for(unsigned int j=i+19; j<i+95; j=j+19) {
					if(kockak[i]->getszoveg()==kockak[j]->getszoveg())
						sorbaszamolo++;
					else
						break;

				}
			}
			nyeresvizsgalat(sorbaszamolo,ideiglenes,_ki_jon,_van_e_nyertes,_start);
			sorbaszamolo=0;

		}
	}


	if(_mennyi_lepes_tortent==400) {
		ideiglenes="PATT, NINCS T�BB HELY! �j j�t�k: s";
	} else {
		if(_ki_jon=="Player 1") {
			_ki_jon="Player 2";
		} else
			_ki_jon="Player 1";
		if(!_van_e_nyertes) {
			ideiglenes=_ki_jon;
			ideiglenes+=" k�vetkezik";
		}
	}
	w->settext(ideiglenes);

}


bool AmobaJatekMester::start(genv::event ev, int &focus)
{
	if(ev.keycode==115) {
		focus=-1;
		_start=true;
		for (unsigned int i=3; i<widgets.size(); i++) {
			delete widgets[i];
		}
		widgets.resize(3);
		kockak.resize(0);
		_ki_jon="Player 1";
		_van_e_nyertes=false;
		w->settext("Player 1 k�vetkezik");
		_mennyi_lepes_tortent=0;
		for (int i=0; i<20; i++) {
			for(int j=0; j<20; j++) {
				kocka  *uj=new kocka(150+j*20,150+i*20,20,20,this);
				kockak.push_back(uj);
				widgets.push_back(uj);
			}
		}
		return true;
	}
	if (_start)
		return true;
	else
		return false;
}

string AmobaJatekMester::getkijon()
{
	return _ki_jon;
}
