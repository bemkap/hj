#pragma once

#include<lua5.2/lua.hpp>
#include<string>
using namespace std;

class instance;

class action {public:
  int r;lua_State*L;
  action(int,lua_State*);
  int operator()(instance*);
};
int getaction(lua_State*);
template<typename T>T getnumeric(lua_State*L,string s){
  lua_getfield(L,-1,s.c_str());
  T r=(T)lua_tonumber(L,-1);
  lua_pop(L,1);
  return r;
}
