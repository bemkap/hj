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
