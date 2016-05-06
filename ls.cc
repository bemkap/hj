#include"en.hh"
#include"lo.hh"
#include"sp.hh"

void loadsps(){
  en&env=eget();
  env.sps.add("sp0",new sp({{0,0},{5,0},{5,5}}));
  env.sps.add("sp1",new sp{{0,0},{8,0},{8,8},{0,8}});
}
