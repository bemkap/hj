#pragma once

#include<lua5.2/lua.hpp>
#include<map>
#include<vector>
#include"common.hh"
#include"instance.hh"
#include"event.hh"
#include"timeline.hh"

class object {
public:
  map<uint,action> handlerkbdo;
  map<uint,action> handlerkbup;
  map<ptbutton,action> handlermousedo;
  map<ptbutton,action> handlermouseup;
  map<uint,action> handlercollision;
  map<string,uint> stats;
  action*create,*step,*destroy,*alarm[11];
  vector<instance*> instances;
  string name,sprite;
  ctimeline*timeline;
  object(const string&,lua_State*);~object();
  void apply(uint,void*);
  void apply(ptbutton,void*);
  //void apply(uint,void*);
  void instancedestroy(instance*);
  instance*instancecreate(float,float);
  instance*operator[](uint);
  void update();
};
