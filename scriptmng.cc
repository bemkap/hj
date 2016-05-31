#include<iostream>
#include"scriptmng.hh"
using namespace std;

cscriptmng::cscriptmng(){
  L=luaL_newstate();
  luaL_openlibs(L);
}
cscriptmng::~cscriptmng(){lua_close(L);}
template<typename T>void parse1(lua_State*L,string s,map<T,action>&d){
  lua_pushnil(L);
  while(lua_next(L,-2)!=0){
    int r=getaction(L);
    T k=(T)getnumeric(L,s);
    d.insert(pair<T,action>(k,action(r,L)));
    lua_pop(L,1);
  }
}
action*parse2(lua_State*L,action*a){
  int r=getaction(L);
  if(!a) a=new action(r,L);
  else{a->r=r;a->L=L;}
  return a;
}
void parse3(lua_State*L,object*o){
  int r=getaction(L);
  uint n=((uint)(getnumeric(L,"n")))%11;
  if(!o->alarm[n]) o->alarm[n]=new action(r,L);
  else{o->alarm[n]->r=r;o->alarm[n]->L=L;}
}
object*cscriptmng::loadobj(const char*f){
  object*o=nullptr;
  if(0<luaL_dofile(L,f)){
    cout<<"lua error file "<<f<<endl;
  }else{
    if(lua_istable(L,-1)){
      o=new object;
      lua_pushnil(L);
      while(lua_next(L,-2)!=0){
	string s=lua_tostring(L,-2);
	if(s=="spr") o->sprite=lua_tostring(L,-1);
	else if(s=="name") o->name=lua_tostring(L,-1);
	else if(s=="ptdo") parse1<ptbutton>(L,"mouse",o->handlermouse);
	else if(s=="kbdo") parse1<uchar>(L,"key",o->handlerkb);
	else if(s=="step") o->step=parse2(L,o->step);
	else if(s=="crte") o->create=parse2(L,o->create);
	else if(s=="dest") o->destroy=parse2(L,o->destroy);
	else if(s=="alrm") parse3(L,o);
	lua_pop(L,1);
      }
    }
  }
  return o;
}
template<typename T>void parsevector(vector<T>&r,lua_State*L){
  lua_pushnil(L);
  while(lua_next(L,-2)!=0){
    r.push_back((T)lua_tonumber(L,-1));
    lua_pop(L,1);
  }
}
csprite*cscriptmng::loadspr(const char*f){
  csprite*s=nullptr;
  if(0<luaL_dofile(L,f)){
    cout<<"lua error file "<<f<<endl;
  }else{
    vector<GLfloat> v,c;
    vector<GLuint> i;
    if(lua_istable(L,-1)){
      s=new csprite;
      lua_pushnil(L);
      while(lua_next(L,-2)!=0){
	string a=lua_tostring(L,-2);
	if(a=="name") s->name=lua_tostring(L,-1);
	else if(a=="vertices") parsevector<GLfloat>(v,L);
	else if(a=="indices") parsevector<GLuint>(i,L);
	/*
	  else if(a=="color"){
	  parsevector<GLfloat>(c,L);
	  s->color.r=c[0];s->color.g=c[1];s->color.b=c[2];
	  }*/
	else if(a=="texture") s->texture(lua_tostring(L,-1));
	lua_pop(L,1);
      }
      s->bind(&i[0],i.size(),&v[0],v.size());
    }
  }
  return s;
}
