#pragma once

#include<lua5.2/lua.hpp>
#include<vector>
#include"event.hh"
using namespace std;

struct node { action a;uint step; };

class ctimeline {
public:
  string name;
  vector<node> nodes;
  bool running;
  ctimeline(const string&,lua_State*);
  void toggle();
};
