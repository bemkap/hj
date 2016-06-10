#include<cmath>
#include"common.hh"
#include"object.hh"
#include"utils.hh"

float pointdirection(float x0,float y0,float x1,float y1){
  float r=atan2(y1-y0,x1-x0);
  return radtodeg(r<0?r+2*PIE:r);
}
float pointdistance(float x0,float y0,float x1,float y1){
  return sqrt(pow(x1-x0,2)+pow(y1-y0,2));
}
float degtorad(float x){
  return x/180*PIE;
}
float radtodeg(float x){
  return x*180/PIE;
}
int sign(float x){  
  return (x>0)-(x<0);
}
int arbitrary(int i){
  uint s=chrono::system_clock::now().time_since_epoch().count();
  minstd_rand0 g(s);
  return g()%i;
}
