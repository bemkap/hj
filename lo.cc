#include"cm.hh"
#include"lo.hh"
#include"en.hh"
#include"in.hh"
#include"ob.hh"
#include"ut.hh"
#include<lua5.2/lua.hpp>
#include<iostream>
using namespace std;

int printkbdo(lua_State*L){
  lua_pushnil(L);
  lua_next(L,-2);
  lua_getfield(L,-1,"act");
  int r=luaL_ref(L,LUA_REGISTRYINDEX);
  lua_pop(L,2);
  return r;
}
void loadobs(){int r;
  lua_State*L=luaL_newstate();
  static const luaL_Reg lualibs[]=
    {{"base",luaopen_base},{"io",luaopen_io},{NULL,NULL}};
  const luaL_Reg*lib=lualibs;
  for(;lib->func!=NULL;lib++){lib->func(L);lua_settop(L,0);}
  luaL_dofile(L,"obs/ship.lua");
  if(lua_istable(L,lua_gettop(L))){
    lua_pushnil(L);
    while(lua_next(L,-2)!=0){
      string s=lua_tostring(L,-2);
      if(s=="spr") {}//printspr(L);
      else if(s=="coll") {}//printcoll(L);
      else if(s=="kbdo") r=printkbdo(L);
      lua_pop(L,1);
    }
  }
  in*i=new in(0,0);
  lua_rawgeti(L,LUA_REGISTRYINDEX,r);
  lua_pushstring(L,"i");lua_pushlightuserdata(L,i);
  cout<<lua_pcall(L,1,0,0)<<endl;
  lua_close(L);
}
