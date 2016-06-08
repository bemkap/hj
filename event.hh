#pragma once

#include"instance.hh"
#include<lua5.2/lua.hpp>
#include<string>
using namespace std;

class action {
public:
  int r;lua_State*L;
  action(int,lua_State*);
  int operator()(instance*);
};
action getaction(lua_State*);
double getnumeric(lua_State*,string);
