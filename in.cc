#include<cmath>
#include"in.hh"
#include"cm.hh"
#include"ut.hh"

in::in(float x,float y):x(x),y(y){
  spe=dir=vsp=hsp=gr=fr=0;
  xsc=ysc=1;
  del=false;
  tlcurt=tlcurn=0;
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
