#pragma once

#include<lua5.2/lua.hpp>
#include<vector>
#include<tuple>

class room {
public:
  room(const string&,lua_State*);
  int width,height,viewportx,viewporty,viewportw,viewporth;
  string name;
  vector<tuple<string,float,float>> objects;
  vector<int> tiles;
  vector<string> legend;
  void add(string,float,float);
  void move(int,int);
  void scale(float,float);
  void init();
  void display(GLuint);
  void reshape(int,int);
};
