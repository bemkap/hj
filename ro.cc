#include"en.hh"
#include"ro.hh"

ro::ro(int w,int h):w(w),h(h),vpx(0),vpy(0),vpw(w),vph(h){}
void ro::add(string o,double x,double y){
  obs.push_back(tuple<string,double,double>(o,x,y));
}
void ro::move(int xo,int yo){vpx+=xo;vpy+=yo;}
void ro::scal(int xs,int ys){vpw+=xs;vph+=ys;}
void ro::disp(){en&env=eget();
  for(auto t:obs){
    ob*o=env.obs.get(get<0>(t));
    if(o) o->oiadd(get<1>(t),get<2>(t));
  }
}
