#pragma once

#include"instance.hh"

int instancecreate(lua_State*);
int instancedestroy(lua_State*);
int getobject(lua_State*);
int setcamera(lua_State*);

void lua_setfunctions(lua_State*);
void lua_pushinstance(lua_State*,instance*);
void lua_getinstance(lua_State*,instance*);
