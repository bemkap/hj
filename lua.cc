#include"env.hh"
#include"instance.hh"
#include"lua.hh"
#include"object.hh"

int instancecreate(lua_State*L){
  const char*s=lua_tostring(L,1);
  float x=lua_tonumber(L,2);
  float y=lua_tonumber(L,3);
  env::envget().instancecreate(s,x,y);
  return 0;
}
int instancedestroy(lua_State*L){
  const char*s=lua_tostring(L,1);
  instance*i=(instance*)lua_touserdata(L,2);
  object*o=env::envget().objects.get(s);
  if(o&&i) o->instancedestroy(i);
  return 0;
}
