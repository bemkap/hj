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
  map<ptbtn,action> handlermouse;
  map<uint ,action> handlercollision;
  act*create,*step,*destroy,*alarm[11];
  vector<in*> instances;
  sprite*sprite;
  timeline*timeline;
  object(sp*);object();~object();
  void apply(uchar);
  void apply(ptbtn);
  void apply(uint );
  void instancedelete(in*);
  in*  instancecreate(double,double);
  in*  operator[](uint);
  void update();
  void display(double,double,double,double);
};
