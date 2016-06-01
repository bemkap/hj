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
csprite*cscriptmng::loadspr(const char*f){
  csprite*s=nullptr;
  if(0<luaL_dofile(L,f)){
    cout<<"lua error file "<<f<<endl;
  }else{
    GLfloat v[4*5]={0.5,0.5,0, 0,0,
		    0.5,-.5,0, 0,0,
		    -.5,-.5,0, 0,0,
		    -.5,0.5,0, 0,0};
    GLuint i[2*3]={0,1,3, 1,2,3};
    if(lua_istable(L,-1)){
      s=new csprite;
      lua_pushnil(L);
      while(lua_next(L,-2)!=0){
	string a=lua_tostring(L,-2);
	if(a=="name") s->name=lua_tostring(L,-1);
	else if(a=="texture") s->texture(lua_tostring(L,-1));
	else if(a=="tilex") v[3]=v[8]=1+(v[13]=v[18]=lua_tonumber(L,-1));
	else if(a=="tiley") v[4]=v[19]=1+(v[14]=v[9]=lua_tonumber(L,-1));
	lua_pop(L,1);
      }
      s->bind(i,6,v,20);
    }
  }
  return s;
}
