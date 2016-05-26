#include"scriptmng.hh"

cscriptmng::cscriptmng(){L=luaL_newstate();}
cscriptmng::~cscriptmng(){lua_close(L);}
object*cscriptmng::loadobj(const char*f){
  luaL_dofile(L,f);
  object*o=new object;
  string n;
  if(lua_istable(L,-1)){
    lua_pushnil(L);
    while(lua_next(L,-2)!=0){
      string s=lua_tostring(L,-2);
      if(s=="spr") o->sprite=lua_tostring(L,-1);
      if(s=="name") o->name=lua_tostring(L,-1);
      else if(s=="ptdo") parsemouse(o);
      else if(s=="kbdo") parsekeyboard(o);
      else if(s=="step") parsestep(o);
      else if(s=="crte") parsecreate(o);
      else if(s=="dest") parsedestroy(o);
      else if(s=="alrm") parsealarm(o);      
      lua_pop(L,1);
    }
  }
  return o;
}
void cscriptmng::parsekeyboard(object*o){
  int r=getaction(L);
  uchar k=getnumeric<uchar>(L,"key");
  o->handlerkb.insert(pair<uchar,action>(k,action(r,L)));
}
void cscriptmng::parsemouse(object*o){
  int r=getaction(L);
  ptbutton b=getnumeric<ptbutton>(L,"mouse");
  o->handlermouse.insert(pair<ptbutton,action>(b,action(r,L)));
}
void cscriptmng::parsestep(object*o){
  int r=getaction(L);
  if(!o->step) o->step=new action(r,L);
  else{o->step->r=r;o->step->L=L;}
}
void cscriptmng::parsecreate(object*o){
  int r=getaction(L);
  if(!o->create) o->create=new action(r,L);
  else{o->create->r=r;o->create->L=L;}
}
void cscriptmng::parsedestroy(object*o){
  int r=getaction(L);
  if(!o->destroy) o->destroy=new action(r,L);
  else{o->destroy->r=r;o->destroy->L=L;}
}
void cscriptmng::parsealarm(object*o){
  int r=getaction(L);
  uint n=getnumeric<uint>(L,"n")%11;
  if(!o->alarm[n]) o->alarm[n]=new action(r,L);
  else{o->alarm[n]->r=r;o->alarm[n]->L=L;}
}
