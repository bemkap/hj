#pragma once

#include<vector>
#include"polygon.hh"
using namespace std;

struct rgb { double r,g,b; };

class csprite {
public:
  polygon mask;
  rgb color;
  csprite(initializer_list<point>);
  polygon maskget(double,double,double,double);
  void display(double,double,double,double);
};
