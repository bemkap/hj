#include"tl.hh"

tline::tline():st(true){}
void tline::tladd(act a,uint s){
  nds.push_back({a,s});
}
void tline::tltog(){
  st=!st;
}