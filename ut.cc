#include<cmath>
#include"cm.hh"
#include"ut.hh"

float point_direction(float x0,float y0,float x1,float y1){
  float r=atan2(y1-y0,x1-x0);
  return r<0?r+2*PIE:r;
}

float point_distance(float x0,float y0,float x1,float y1){
  return sqrt(pow(x1-x0,2)+pow(y1-y0,2));
}

float degtorad(float x){
  return x/180*PIE;
}

float radtodeg(float x){
  return x*180/PIE;
}
