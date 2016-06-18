#include"event.hh"
#include"lua.hh"
#include<iostream>
using namespace std;

action::action(int r,lua_State*L):r(r),L(L){}
int action::operator()(instance*i){
  lua_rawgeti(L,LUA_REGISTRYINDEX,r);
  lua_pushinstance(L,i);
  if(!lua_pcall(L,0,0,0)) lua_getinstance(L,i);
  return 0;
}
int getaction(lua_State*L){
  lua_getfield(L,-1,"act");
  return luaL_ref(L,LUA_REGISTRYINDEX);
}
float getnumeric(lua_State*L,const char*s){
  lua_getfield(L,-1,s);
  float r=lua_tonumber(L,-1);
  lua_pop(L,1);
  return r;
}
