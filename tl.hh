#pragma once

#include<lua5.2/lua.hpp>
#include<vector>
#include"ev.hh"
using namespace std;

struct node { ehdl h;uint step; };

class tl {public:
  lua_State*L;
  vector<node> nds;
  bool st;
  tl(lua_State*);
  void tladd(uint,int);
  void tltog();
};
