#pragma once

#include<GL/glew.h>
#include<lua5.2/lua.hpp>
#include<string>
#include"common.hh"
using namespace std;

enum instate { NOTDEAD,DEAD };

class instance {
public:
  float x,y;
  float speed,direction,vspeed,hspeed,gravity,friction;
  float imagespeed,imageindex,imagerotation;
  float xscale,yscale;
  instate state;
  string sprite;
  uint tltime,tlnode;
  uint alarm[11];
  instance(float,float,string);
  void move();
  void setmodel(GLuint);
};
