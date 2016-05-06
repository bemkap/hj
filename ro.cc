#include"ro.hh"

void ro::add(ob*o,double x,double y){
  obs.push_back(tuple<ob*,double,double>(o,x,y));
}
void ro::disp(){
  for(auto i:obs){
    ob*o=get<0>(i);
    if(o->spr) o->spr->disp(get<1>(i),get<2>(i),1,1);
  }
}
