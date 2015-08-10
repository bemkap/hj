#include<cmath>
#include"in.hh"
#include"cm.hh"

in::in(float x,float y):x(x),y(y),sp(0),di(0),vsp(0),hsp(0),del(false){}
void in::move(){
  x+=hsp;
  y+=vsp;
  x+=sp*cos(di/180*PIE);
  y+=sp*sin(di/180*PIE);
}
