#pragma once

#include<lua5.2/lua.hpp>
#include"cm.hh"
using namespace std;

enum inst { BORN,LIVE,DEAD };

class in {public:
  double x,y;
  double spe,dir,vsp,hsp,gr,fr;
  double xsc,ysc;
  inst st;
  uint tlcurt,tlcurn;
  uint alrn[11];
  in(double,double);
  void move();
};
int xy(lua_State*);
