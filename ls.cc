#include"en.hh"
#include"ls.hh"
#include"sp.hh"

void loadsps(){
  en&env=eget();
  env.esadd("sp0",new sp({{0,0},{5,0},{5,5}}));
  env.esadd("sp1",new sp{{0,0},{8,0},{8,8},{0,8}});
}
