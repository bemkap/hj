#pragma once

#include<lua5.2/lua.hpp>
#include"in.hh"
using namespace std;

class act {public:
  int r;lua_State*L;
  act(int,lua_State*);
  int operator()(in*);
};
