#pragma once

#include<vector>
#include"polygon.hh"
using namespace std;

struct color { double r,g,b; };

class sprite {
public:
  poly mask;
  color color;
  sprite(initializer_list<point>);
  polygon maskget(double,double,double,double);
  void display(double,double,double,double);
};
