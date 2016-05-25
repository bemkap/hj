#pragma once

#include<lua5.2/lua.hpp>
#include<vector>
#include"event.hh"
using namespace std;

struct node { action a;uint step; };

class ctimeline {
public:
  lua_State*L;
  vector<node> nodes;
  bool state;
  ctimeline(lua_State*);
  void nodeadd(action,uint);
  void toggle();
};
