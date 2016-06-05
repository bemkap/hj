#include<algorithm>
#include"common.hh"
#include"env.hh"
#include"dict.hh"
#include"object.hh"

object::object():timeline(nullptr){
  create=step=destroy=nullptr;
  for(uint i=0;i<11;++i) alarm[i]=nullptr;
<<<<<<< HEAD
  if(0<luaL_dofile(L,file)){
    cout<<"lua error file "<<file<<endl;
  }else{
    if(lua_istable(L,-1)){
      lua_pushnil(L);
      while(lua_next(L,-2)!=0){
	string s=lua_tostring(L,-2);
	if(s=="spr") sprite=lua_tostring(L,-1);
	else if(s=="name") name=lua_tostring(L,-1);
	else if(s=="stats"){
	  lua_pushnil(L);
	  stats[lua_tostring(L,-2)]=lua_tonumber(L,-1);
	  lua_pop(L,1);
	}
	lua_pop(L,1);
      }
    }
  }
=======
>>>>>>> parent of d7b0130... isometric? generico o ..?
}
object::~object(){
  for(auto i:instances) delete i;
  if(create) delete create;
  if(step) delete step;
  if(destroy) delete destroy;
  for(uint i=0;i<11;++i) if(alarm[i]) delete alarm[i];
  if(timeline) delete timeline;
}
void object::apply(uchar k){
  auto a=handlerkb.find(k);
  if(a!=handlerkb.end()) for(auto i:instances) ((*a).second)(i);
}
void object::apply(uint n){
  auto a=handlercollision.find(n);
  if(a!=handlercollision.end()) for(auto i:instances) ((*a).second)(i);
}
void object::instancedestroy(instance*i){
  if(destroy) (*destroy)(i);
  i->state=DEAD;
}
instance*object::instancecreate(double x,double y){
  instance*i=new instance(x,y);
  if(create) (*create)(i);
  instances.push_back(i);
  return i;
}
instance*object::operator[](uint i){
  try{return instances.at(i);}
  catch(out_of_range e){return nullptr;}
}
void object::update(){
  if(step) for(auto i:instances) (*step)(i);
  for(int i=0;i<11;++i)
    if(alarm[i])
      for(auto j:instances)
	if(j->alarm[i]>0&&--j->alarm[i]<=0) (*alarm[i])(j);
  /*
  if(tline&&tline->st)
    for(auto&i:ins)
      if(++i->tlcurt>=tline->nds[i->tlcurn].step){
	tline->nds[i->tlcurn].a(i);
	if(i->tlcurn<tline->nds.size()-1) ++i->tlcurn;
	else tline->st=false;
      }
  */
  for(auto i:instances) i->move();
  remove_if(instances.begin(),instances.end(),
	    [](instance*i){return i->state==DEAD;});
}
