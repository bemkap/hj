#pragma once

#include<vector>
#include<tuple>
#include"ob.hh"

class ro {public:
  vector<tuple<ob*,double,double>> obs;
  void add(ob*,double,double);
  void disp();
};
