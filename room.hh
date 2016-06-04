#pragma once

#include<lua5.2/lua.hpp>
#include<vector>
#include<tuple>

class room {
public:
  room(const char*,lua_State*);
  int width,height,viewportx,viewporty,viewportw,viewporth;
  string name;
  vector<tuple<string,double,double>> objects;
  void add(string,double,double);
  void move(int,int);
  void scale(double,double);
  void display();
  void reshape(int,int);
};
