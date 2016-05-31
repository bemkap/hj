#pragma once

#include<lua5.2/lua.hpp>
#include"object.hh"
#include"sprite.hh"
using namespace std;

class cscriptmng {
public:
  cscriptmng();~cscriptmng();
  object*loadobj(const char*);
  csprite*loadspr(const char*);
protected:
  lua_State*L;
};
