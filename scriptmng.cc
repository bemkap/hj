#include"scriptmng.hh"

scriptmng::scriptmng(){L=luaL_newstate();}
scriptmng::~scriptmng(){lua_close(L);}
object*scriptmng::loadobj(const char*f){
  luaL_dofile(L,f);
  object*o=new object;
  if(lua_istable(L,lua_gettop(L))){
    lua_pushnil(L);
    while(lua_next(L,-2)!=0){
      string s=lua_tostring(L,-2);
      if(s=="spr") o->sprite=sprites.get(lua_tostring(L,-1));
      else if(s=="ptdo") parsemouse(o);
      else if(s=="kbdo") parsekeyboard(o);
      else if(s=="step") parsestep(o);
      lua_pop(L,1);
    }
  }
  return o;
}
void scriptmng::parsekeyboard(object*o){
  int r=getaction(L);
  uchar k=getnumeric<uchar>(L,"key");
  o->handlerkb.insert(pair<uchar,action>(k,action(r,L)));
}
void scriptmng::parsemouse(object*o){
  int r=getaction(L);
  ptbutton k=getnumeric<ptbutton>(L,"mouse");
  o->handlermouse.insert(pair<ptbutton,action>(k,action(r,L)));
}
void scriptmng::parsestep(object*o){
  int r=getaction(L);
  if(!o->step) o->step=new action(r,L);
  else{o->step->r=r;o->step->L=L;}
}
