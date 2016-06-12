#include"event.hh"
#include<iostream>
using namespace std;

action::action(int r,lua_State*L):r(r),L(L){}
int action::operator()(instance*i){
  lua_rawgeti(L,LUA_REGISTRYINDEX,r);
  float*v[]={&i->x,&i->y,&i->speed,&i->direction,
	     &i->vspeed,&i->hspeed,&i->gravity,&i->friction,
	     &i->imagespeed,&i->imageindex,&i->xscale,&i->yscale};
  const char*f[]={"x","y","speed","direction",
		  "vspeed","hspeed","gravity","friction",
		  "imagespeed","imageindex","xscale","yscale",NULL};
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
  return luaL_ref(L,LUA_REGISTRYINDEX);
}
float getnumeric(lua_State*L,const char*s){
  lua_getfield(L,-1,s);
  float r=lua_tonumber(L,-1);
  lua_pop(L,1);
  return r;
}
