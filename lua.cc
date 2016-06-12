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
int getobject(lua_State*L){
  const char*s=lua_tostring(L,1);
  object*o=env::envget().objects.get(s);
  if(o&&o->instances.size()>0){
    instance*i=o[0];
    float*v[]={&i->x,&i->y,&i->speed,&i->direction,
	       &i->vspeed,&i->hspeed,&i->gravity,&i->friction,
	       &i->imagespeed,&i->imageindex,&i->xscale,&i->yscale};
    const char*f[]={"x","y","speed","direction",
		    "vspeed","hspeed","gravity","friction",
		    "imagespeed","imageindex","xscale","yscale",NULL};
    lua_newtable(L);
    for(int j=0;f[j];++j){
      lua_pushlstring(L,f[j]);
      lua_pushnumber(L,*v[j]);
      lua_settable(L,-1);
    }
  }
  return 1;
}
