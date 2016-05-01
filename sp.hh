#pragma once

#include<vector>
#include"ge.hh"
using namespace std;

struct color { double r,g,b; };

class sp {public:
  poly msk;
  color c;
  sp(initializer_list<point>);
  poly smget(double,double,double,double);
  void disp(double,double,double,double);
};
