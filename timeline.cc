#include"common.hh"
#include"timeline.hh"

ctimeline::ctimeline(lua_State*M):L(M),state(true){}
void ctimeline::nodeadd(action a,uint s){
  nodes.push_back({a,s});
}
void ctimeline::toggle(){
  state=!state;
}
