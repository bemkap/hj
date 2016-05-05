#pragma once

#include<lua.hpp>
#include<iostream>
using namespace std;

class lua {public:
  lua_State*st;
  lua();~lua();
};

void oplib(lua_State*);
void exall(lua_State*,const string&);
