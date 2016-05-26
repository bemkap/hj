#pragma once

#include<map>
#include<vector>
#include"common.hh"
#include"instance.hh"
#include"event.hh"
#include"timeline.hh"

class object {
public:
  map<uchar,action> handlerkb;
  map<ptbutton,action> handlermouse;
  map<uint,action> handlercollision;
  action*create,*step,*destroy,*alarm[11];
  vector<instance*> instances;
  string name,sprite;
  ctimeline*timeline;
  object(string);object();~object();
  void apply(uchar);
  void apply(ptbutton);
  void apply(uint);
  void instancedelete(instance*);
  instance*instancecreate(double,double);
  instance*operator[](uint);
  void update();
};