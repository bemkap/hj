#include"timeline.hh"

ctimeline::ctimeline(lua_State*M):L(M),st(true){}
void ctimeline::timelineadd(action a,uint s){
  nodes.push_back({a,s});
}
void ctimeline::timelinetog(){
  state=!state;
}
