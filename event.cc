#include"event.hh"
#include<iostream>
using namespace std;

action::action(int r,lua_State*L):r(r),L(L){}
int action::operator()(instance*i){
  lua_rawgeti(L,LUA_REGISTRYINDEX,r);
  lua_pushlightuserdata(L,i);
  return lua_pcall(L,1,0,0);
}
int getaction(lua_State*L){
  lua_getfield(L,-1,"act");
  int r=luaL_ref(L,LUA_REGISTRYINDEX);
  return r;
}
