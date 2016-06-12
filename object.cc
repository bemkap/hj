#include<algorithm>
#include"common.hh"
#include"env.hh"
#include"dict.hh"
#include"object.hh"

template<typename T>void parse1(lua_State*L,map<T,action>&m,const char*s){
  lua_pushnil(L);
  while(lua_next(L,-2)!=0){
    int a=getaction(L);
    T k=(T)getnumeric(L,s);
    m.insert(pair<T,action>(k,action(a,L)));
    lua_pop(L,1);
  }
}
object::object(const string&file,lua_State*L):timeline(nullptr){
  create=step=destroy=nullptr;
  for(uint i=0;i<11;++i) alarm[i]=nullptr;
  if(0<luaL_dofile(L,file.c_str())){
    cout<<"ERROR::LUA::OBJECT::"<<file<<endl;
  }else{
    int n=file.find_last_of("/\\")+1;
    int m=file.find_last_of(".");    
    if(lua_istable(L,-1)){
      name=file.substr(n,m-n);
      lua_pushnil(L);
      while(lua_next(L,-2)!=0){
	string s=lua_tostring(L,-2);
	if(s=="sprite") sprite=lua_tostring(L,-1);
	else if(s=="kbdo") parse1(L,handlerkbdo,"key");
	else if(s=="kbup") parse1(L,handlerkbup,"key");
	else if(s=="ptdo") parse1(L,handlermousedo,"button");
	else if(s=="ptup") parse1(L,handlermouseup,"button");
	else if(s=="crte") create=new action(getaction(L),L);
	else if(s=="dest") destroy=new action(getaction(L),L);
	else if(s=="step") step=new action(getaction(L),L);
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
void object::apply(uint k,void*extra){
  bool press=extra;
  map<uint,action>&m=press?handlerkbdo:handlerkbup;
  auto a=m.find(k);
  if(a!=m.end()) for(auto i:instances) ((*a).second)(i);
}
void object::apply(ptbutton b,void*extra){
  bool press=extra;
  map<ptbutton,action>&m=press?handlermousedo:handlermouseup;
  auto a=m.find(b);
  if(a!=m.end()) for(auto i:instances) ((*a).second)(i);
}
/*
void object::apply(uint n,void*extra){
  auto a=handlercollision.find(n);
  if(a!=handlercollision.end()) for(auto i:instances) ((*a).second)(i);
}
*/
void object::instancedestroy(instance*i){
  if(destroy) (*destroy)(i);
  i->state=DEAD;
}
instance*object::instancecreate(float x,float y){
  instance*i=new instance(x,y,sprite);
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
  if(timeline&&timeline->running)
    for(auto i:instances)
      if(++i->tltime>=timeline->nodes[i->tlnode].step){
	timeline->nodes[i->tlnode].a(i);
	if(i->tlnode<timeline->nodes.size()-1) ++i->tlnode;
	else timeline->running=false;
      }
  for(auto i:instances) i->move();
  remove_if(instances.begin(),instances.end(),
	    [](instance*i){return i->state==DEAD;});
}
