#include"scriptmng.hh"

scriptmng::scriptmng(){L=luaL_newstate();}
scriptmng::~scriptmng(){if(L) lua_close(L);}
ob*scriptmng::loadobj(const char*f){
  luaL_dofile(L,(*i).path().string().c_str());
  ob*o=new ob;
  if(lua_istable(L,lua_gettop(L))){
    lua_pushnil(L);
    while(lua_next(L,-2)!=0){
      string s=lua_tostring(L,-2);
      if(s=="spr") o->spr=sps.get(lua_tostring(L,-1));
      else if(s=="ptdo") parseptdo(o);
      else if(s=="kbdo") parsekbdo(o);
      else if(s=="step") parsestep(o);
      lua_pop(L,1);
    }
  }
  return o;
}
