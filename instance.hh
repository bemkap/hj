#pragma once

#include<GL/glew.h>
#include<lua5.2/lua.hpp>
#include"common.hh"
#include"sprite.hh"

enum instate { NOTDEAD,DEAD };

class instance {
public:
  float x,y;
  float speed,direction,vspeed,hspeed,gravity,friction;
  float imagespeed,current;
  float xscale,yscale;
  instate state;
  csprite*sprite;
  uint tltime,tlnode;
  uint alarm[11];
  instance(float,float,csprite*);
  void move();
  void display(GLuint);
};
