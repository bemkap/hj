#pragma once

#include<lua5.2/lua.hpp>
#include"common.hh"

enum instate { NOTDEAD,DEAD };

class instance {
public:
  double x,y;
  double speed,direction,vspeed,hspeed,gravity,friction;
  double xscale,yscale;
  instate state;
  uint tltime,tlnode;
  uint alarm[11];
  instance(double,double);
  void move();
};
int translate(lua_State*);
int set(lua_State*);
void inregister(lua_State*);
