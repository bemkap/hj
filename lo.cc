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
  luaL_openlibs(L);
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
  act a(r,L);
  in*i=new in(10,10);
  a(i);
  cout<<i->x<<" "<<i->y<<endl;
  delete i;
  lua_close(L);
}
