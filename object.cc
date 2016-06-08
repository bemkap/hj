#include<algorithm>
#include"common.hh"
#include"env.hh"
#include"dict.hh"
#include"object.hh"

object::object(string file,lua_State*L):timeline(nullptr){
  create=step=destroy=nullptr;
  for(uint i=0;i<11;++i) alarm[i]=nullptr;
  if(0<luaL_dofile(L,file.c_str())){
    cout<<"lua error file "<<file<<endl;
  }else{
    int n=file.find_last_of("/\\");
    int m=file.find_last_of(".");
    name=file.substr(n+1,m);
    if(lua_istable(L,-1)){
      lua_pushnil(L);
      while(lua_next(L,-2)!=0){
	string s=lua_tostring(L,-2);
	if(s=="sprite") sprite=lua_tostring(L,-1);
	else if(s=="kbdo"){
	  lua_pushnil(L);
	  while(lua_next(L,-2)!=0){
	    action a=getaction(L);
	    uchar k=(uchar)getnumeric(L,"key");
	    handlerkb[k]=a;
	    lua_pop(L,1);
	  }
	}
	lua_pop(L,1);
      }
    }
  }
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
void object::apply(ptbutton b){
  auto a=handlermouse.find(b);
  if(a!=handlermouse.end()) for(auto i:instances) ((*a).second)(i);
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
