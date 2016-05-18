#include"tl.hh"

tl::tl(lua_State*M):L(M),st(true){}
void tl::tladd(uint s,int r){
  estp h(L);h.r=r;
  nds.push_back({h,s});
}
void tl::tltog(){
  st=!st;
}
