#include"timeline.hh"

tl::tl(lua_State*M):L(M),st(true){}
void tl::tladd(act a,uint s){
  nds.push_back({a,s});
}
void tl::tltog(){
  st=!st;
}
