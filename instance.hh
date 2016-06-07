#pragma once

#include"common.hh"
#include<glm/glm.hpp>
using namespace glm;

enum instate { NOTDEAD,DEAD };

class instance {
public:
  vec2 xy,movement;
  double hp[2],mp[2],atk[2],def[2],agi[2],inl[2],con[2];
  instate state;
  instance(double,double);
  void move();
};
