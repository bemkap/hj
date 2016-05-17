#include"tl.hh"

tl::tl(lua_State*M):L(M),st(true){}
void tl::tladd(uint s,int r){
  nds.push_back({r,s});
}
void tl::tltog(){
  st=!st;
}
