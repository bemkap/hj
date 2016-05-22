#pragma once

#include<lua5.2/lua.hpp>
#include<vector>
#include"event.hh"
using namespace std;

struct node { act a;uint step; };

class timeline {
public:
  lua_State*L;
  vector<node> nodes;
  bool state;
  timeline(lua_State*);
  void nodeadd(act,uint);
  void toggle();
};
