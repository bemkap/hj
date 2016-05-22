#pragma once

#include<lua5.2/lua.hpp>
#include"common.hh"

enum instate { NOTDEAD,DEAD };

class instance {
public:
  double x,y;
  double spe,dir,vsp,hsp,gr,fr;
  double xsc,ysc;
  instate st;
  uint tlcurt,tlcurn;
  uint alrn[11];
  instance(double,double);
  void move();
};
int translate(lua_State*);
int set(lua_State*);
void inregister(lua_State*);
