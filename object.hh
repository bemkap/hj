#pragma once

#include<map>
#include<vector>
#include<lua5.2/lua.hpp>
#include"common.hh"
#include"instance.hh"
#include"event.hh"
#include"timeline.hh"

class object {
public:
  map<uchar,action> handlerkb;
  map<uint,action> handlercollision;
  map<string,uint> stats;
  action*create,*step,*destroy,*alarm[11];
  vector<instance*> instances;
  string name,sprite;
  ctimeline*timeline;
  object(const char*,lua_State*);~object();
  void apply(uchar);
  void apply(uint);
  void instancedestroy(instance*);
  instance*instancecreate(double,double);
  instance*operator[](uint);
  void update();
};
