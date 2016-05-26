#include<cmath>
#include"common.hh"
#include"object.hh"
#include"utils.hh"

double pointdirection(double x0,double y0,double x1,double y1){
  double r=atan2(y1-y0,x1-x0);
  return radtodeg(r<0?r+2*PIE:r);
}
double pointdistance(double x0,double y0,double x1,double y1){
  return sqrt(pow(x1-x0,2)+pow(y1-y0,2));
}
double degtorad(double x){
  return x/180*PIE;
}
double radtodeg(double x){
  return x*180/PIE;
}
int sign(double x){  
  return (x>0)-(x<0);
}
int arbitrary(int i){
  uint s=chrono::system_clock::now().time_since_epoch().count();
  minstd_rand0 g(s);
  return g()%i;
}