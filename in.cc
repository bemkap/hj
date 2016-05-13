#include<cmath>
#include"in.hh"
#include"cm.hh"
#include"ut.hh"

in::in(double x,double y):x(x),y(y){
  spe=dir=vsp=hsp=gr=fr=0;
  xsc=ysc=1;
  st=BORN;
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
int xy(lua_State*L){
  //in*i=(in*)lua_touserdata(L,-1);
  double xx=lua_tonumber(L,-1);
  double yy=lua_tonumber(L,-2);
  cout<<xx<<" "<<yy<<endl;
  //i->x+=xx;
  //i->y+=yy;
  return 0;
}
