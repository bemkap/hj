#pragma once

#include<map>
#include<vector>
#include"common.hh"
#include"instance.hh"
#include"event.hh"
#include"sprite.hh"
#include"timeline.hh"

class object {
public:
  map<uchar,action> handlerkb;
  map<ptbutton,action> handlermouse;
  map<uint,action> handlercollision;
  action*create,*step,*destroy,*alarm[11];
  vector<instance*> instances;
  csprite*sprite;
  ctimeline*timeline;
  object(csprite*);object();~object();
  void apply(uchar);
  void apply(ptbutton);
  void apply(uint);
  void instancedelete(instance*);
  instance*instancecreate(double,double);
  instance*operator[](uint);
  void update();
  void display(double,double,double,double);
};
