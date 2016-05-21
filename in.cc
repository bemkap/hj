#include<cmath>
#include"in.hh"
#include"cm.hh"
#include"ut.hh"

in::in(double x,double y):x(x),y(y){
  spe=dir=vsp=hsp=gr=fr=0;
  xsc=ysc=1;
  st=NOTDEAD;
  tlcurt=tlcurn=0;
  for(int i=0;i<11;++i) alrn[i]=0;
}
void in::move(){
  x+=hsp;
  y+=vsp;
  x+=spe*cos(degtorad(dir));
  y+=spe*sin(degtorad(dir));
  vsp-=gr;
  hsp-=fr*sign(hsp);
  vsp-=fr*sign(vsp);
  spe-=fr*sign(spe);
}
int tr(lua_State*L){
  in*i=(in*)lua_touserdata(L,1);
  double tx=lua_tonumber(L,2);
  double ty=lua_tonumber(L,3);
  i->x+=tx;
  i->y+=ty;
  return 0;
} 
int set(lua_State*L){
  in*i=(in*)lua_touserdata(L,1);
  double tx=lua_tonumber(L,2);
  double ty=lua_tonumber(L,3);
  i->x=tx;
  i->y=ty;
  return 0;
}
void inreg(lua_State*L){
  lua_pushcfunction(L,tr);
  lua_setglobal(L,"tr");
  lua_pushcfunction(L,set);
  lua_setglobal(L,"set");
}
