#pragma once

#include<lua5.2/lua.hpp>
#include"object.hh"
using namespace std;

class cscriptmng {
public:
  cscriptmng();~cscriptmng();
  object*loadobj(const char*);
  void parsesprite(object*);
  void parsekeyboard(object*);
  void parsemouse(object*);
  void parsestep(object*);
  void parsealarm(object*);
  void parsedestroy(object*);
  void parsecreate(object*);
protected:
  lua_State*L;
};
