#include<cmath>
#include"instance.hh"
#include"common.hh"
#include"utils.hh"

instance::instance(double x,double y){
  xy.x=x;
  xy.y=y;
  state=NOTDEAD;
}
void instance::move(){
  xy+=movement;
}
