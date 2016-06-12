#pragma once

int instancecreate(lua_State*);
int instancedestroy(lua_State*);
int getobject(lua_State*);

void lua_setfunctions(lua_State*);
