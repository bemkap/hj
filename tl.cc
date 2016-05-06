#include"tl.hh"

tl::tl():st(true){}
void tl::tladd(uint s,act a){
  nds.push_back({a,s});
}
void tl::tltog(){
  st=!st;
}
