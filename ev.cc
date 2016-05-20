#include"ev.hh"
#include<iostream>
using namespace std;

act::act(int r,lua_State*L):r(r),L(L){}
int act::operator()(in*i){
  lua_rawgeti(L,LUA_REGISTRYINDEX,r);
  lua_pushlightuserdata(L,i);
  if(!lua_pcall(L,1,1,0)){
    lua_getfield(L,lua_gettop(L),"ry");
    if(!lua_isnil(L,lua_gettop(L)))
      i->y+=lua_tonumber(L,lua_gettop(L));
    lua_pop(L,1);
    lua_getfield(L,lua_gettop(L),"rx");
    if(!lua_isnil(L,lua_gettop(L)))
      i->x+=lua_tonumber(L,lua_gettop(L));
    lua_pop(L,1);
  }else return 1;
  return 0;
}
