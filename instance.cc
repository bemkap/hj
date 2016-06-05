#include<cmath>
#include"instance.hh"
#include"common.hh"
#include"utils.hh"

instance::instance(double x,double y):x(x),y(y){
  state=NOTDEAD;
}
void instance::move(){
  x+=hspeed;
  y+=vspeed;
}
