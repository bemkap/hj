#pragma once

#include<lua5.2/lua.hpp>
#include"cm.hh"

enum inst { NOTDEAD,DEAD };

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
int tr(lua_State*);
int set(lua_State*);
void inreg(lua_State*);
