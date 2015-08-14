#include<cmath>
#include"in.hh"
#include"cm.hh"
#include"ut.hh"

in::in(float x,float y):x(x),y(y),sp(0),di(0),vsp(0),hsp(0),xsc(1),ysc(1),del(false),tlcurt(0){}
void in::move(){
  x+=hsp;
  y+=vsp;
  x+=sp*cos(degtorad(di));
  y+=sp*sin(degtorad(di));
}
