#include<cmath>
#include"instance.hh"
#include"common.hh"
#include"utils.hh"

instance::instance(double x,double y):x(x),y(y){
  speed=direction=vspeed=hspeed=gravity=friction=0;
  xscale=yscale=1;
  state=NOTDEAD;
  tltime=tlnode=0;
  for(int i=0;i<11;++i) alarm[i]=0;
}
void instance::move(){
  x+=hspeed;
  y+=vspeed;
  x+=speed*cos(degtorad(direction));
  y+=speed*sin(degtorad(direction));
  vspeed-=gravity;
  hspeed-=friction*sign(hspeed);
  vspeed-=friction*sign(vspeed);
  speed-=friction*sign(speed);
}
int translate(lua_State*L){
  instance*i=(instance*)lua_touserdata(L,1);
  double tx=lua_tonumber(L,2);
  double ty=lua_tonumber(L,3);
  i->x+=tx;
  i->y+=ty;
  return 0;
} 
int set(lua_State*L){
  instance*i=(instance*)lua_touserdata(L,1);
  double tx=lua_tonumber(L,2);
  double ty=lua_tonumber(L,3);
  i->x=tx;
  i->y=ty;
  return 0;
}
void inregister(lua_State*L){
  lua_pushcfunction(L,translate);
  lua_setglobal(L,"translate");
  lua_pushcfunction(L,set);
  lua_setglobal(L,"set");
}
