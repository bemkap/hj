#include"event.hh"
#include<iostream>
using namespace std;

action::action(int r,lua_State*L):r(r),L(L){}
int action::operator()(instance*i){
  lua_rawgeti(L,LUA_REGISTRYINDEX,r);
  double*v[]={&i->x,&i->y,&i->speed,&i->direction,
	      &i->vspeed,&i->hspeed,&i->gravity,&i->friction};
  const char*f[]={"x","y","speed","direction","vspeed",
		  "hspeed","gravity","friction",NULL};
  for(int i=0;f[i];++i){
    lua_pushnumber(L,*v[i]);
    lua_setglobal(L,f[i]);
  }
  int r;
  if(!(r=lua_pcall(L,0,0,0))){
    for(int i=0;f[i];++i){
      lua_getglobal(L,f[i]);
      *v[i]=lua_tonumber(L,-1);
      lua_pop(L,1);
    }
  }
  return r;
}
int getaction(lua_State*L){
  lua_getfield(L,-1,"act");
  int r=luaL_ref(L,LUA_REGISTRYINDEX);
  return r;
}
double getnumeric(lua_State*L,string s){
  lua_getfield(L,-1,s.c_str());
  double r=lua_tonumber(L,-1);
  lua_pop(L,1);
  return r;
}
