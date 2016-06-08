#include"env.hh"
#include"room.hh"

room::room(int w,int h):width(w),height(h),viewportw(w),viewporth(h){
  viewportx=viewporty=0;
}
void room::add(string o,double x,double y){
  objects.push_back(tuple<string,double,double>(o,x,y));
}
void room::move(int xo,int yo){viewportx+=xo;viewporty+=yo;}
void room::scale(double xs,double ys){viewportw*=xs;viewporth*=ys;}
void room::display(){
  env&env=env::envget();
  for(auto t:objects){
    object*o=env.objects.get(get<0>(t));
    if(o) o->instancecreate(get<1>(t),get<2>(t));
  }
}
void room::reshape(int w,int h){scale(w/viewportw,h/viewporth);}
