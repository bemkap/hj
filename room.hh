#pragma once

#include<vector>
#include<tuple>

class room {
public:
  room(int,int);
  int width,height,viewportx,viewporty,viewportw,viewporth;
  vector<tuple<string,double,double>> objects;
  void add(string,double,double);
  void move(int,int);
  void scale(double,double);
  void display();
  void reshape(int,int);
};
