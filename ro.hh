#pragma once

#include<vector>
#include<tuple>

class ro {public:
  ro(int,int);
  int w,h,vpx,vpy,vpw,vph;
  vector<tuple<string,double,double>> obs;
  void add(string,double,double);
  void move(int,int);
  void scal(int,int);
  void disp();
};
