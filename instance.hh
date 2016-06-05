#pragma once

#include"common.hh"

enum instate { NOTDEAD,DEAD };

class instance {
public:
  double x,y;
  double hp[2],mp[2],attack[2],defense[2],agility[2];
  double intelligence[2],concentration[2];
  double hspeed,vspeed;
  instate state;
  uint alarm[11];
  instance(double,double);
  void move();
};
