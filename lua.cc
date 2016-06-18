#include"env.hh"
#include"instance.hh"
#include"lua.hh"
#include"object.hh"

int instancecreate(lua_State*L){
  const char*s=lua_tostring(L,1);
  float x=lua_tonumber(L,2);
  float y=lua_tonumber(L,3);
  lua_pushinstance(L,env::envget().instancecreate(s,x,y));
  return 1;
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
  if(o&&o->instances.size()>0) lua_pushinstance(L,(*o)[0]);
  else lua_pushnil(L);
  return 1;
}
int setcamera(lua_State*L){
  float x=lua_tonumber(L,1);
  float y=lua_tonumber(L,2);
  env::envget().graphicmng.xcenter=x;
  env::envget().graphicmng.ycenter=y;
  return 0;
}  
void lua_setfunctions(lua_State*L){
  lua_register(L,"instancecreate",instancecreate);
  lua_register(L,"instancedestroy",instancedestroy);
  lua_register(L,"getobject",getobject);
  lua_register(L,"setcamera",setcamera);
}
void lua_pushinstance(lua_State*L,instance*i){
  float*v[]={&i->x,&i->y,&i->speed,&i->direction,
	     &i->vspeed,&i->hspeed,&i->gravity,&i->friction,
	     &i->imagespeed,&i->imageindex,&i->xscale,&i->yscale};
  const char*f[]={"x","y","speed","direction",
		  "vspeed","hspeed","gravity","friction",
		  "imagespeed","imageindex","xscale","yscale",NULL};
  lua_pushstring(L,i->sprite.c_str());
  lua_setglobal(L,"sprite");
  for(int i=0;f[i];++i){
    lua_pushnumber(L,*v[i]);
    lua_setglobal(L,f[i]);
  }
}
void lua_getinstance(lua_State*L,instance*i){
  float*v[]={&i->x,&i->y,&i->speed,&i->direction,
	     &i->vspeed,&i->hspeed,&i->gravity,&i->friction,
	     &i->imagespeed,&i->imageindex,&i->xscale,&i->yscale};
  const char*f[]={"x","y","speed","direction",
		  "vspeed","hspeed","gravity","friction",
		  "imagespeed","imageindex","xscale","yscale",NULL};  
  for(int i=0;f[i];++i){
    lua_getglobal(L,f[i]);
    *v[i]=lua_tonumber(L,-1);
    lua_pop(L,1);
  }
  lua_getglobal(L,"sprite");
  i->sprite=lua_tostring(L,-1);
  lua_pop(L,1);
}
