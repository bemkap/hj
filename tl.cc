#include"tl.hh"

tline::tline():st(true){}
void tline::tladd(uint s,act a){
  nds.push_back({a,s});
}
void tline::tltog(){
  st=!st;
}
