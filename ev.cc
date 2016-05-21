#include"ev.hh"
#include<iostream>
using namespace std;

act::act(int r,lua_State*L):r(r),L(L){}
int act::operator()(in*i){
  lua_rawgeti(L,LUA_REGISTRYINDEX,r);
  lua_pushlightuserdata(L,i);
  return lua_pcall(L,1,0,0);
}
