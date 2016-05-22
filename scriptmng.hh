#pragma once

#include<lua5.2/lua.hpp>
#include"object.hh"

class scriptmng {
  lua_State*L;
  scriptmng();~scriptmng();
  ob*loadobj(const char*);
  void parsesprite(ob*);
  void parsekeyboard(ob*);
  void parsemouse(ob*);
  void parsestep(ob*);
  //void parsealarm(ob*);
  //void parsedestroy(ob*);
  //void parsecreate(ob*);
};
