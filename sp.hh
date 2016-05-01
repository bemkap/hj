#pragma once

#include<vector>
#include"ge.hh"
using namespace std;

struct color { float r,g,b; };

class sp {public:
  poly msk;
  color c;
  sp(initializer_list<point>);
  poly smget(float,float,float,float);
  void disp(float,float,float,float);
};
