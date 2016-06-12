#include<iostream>
#include"common.hh"
#include"timeline.hh"

ctimeline::ctimeline(const string&file,lua_State*L):running(true){
  if(0<luaL_dofile(L,file.c_str())){
    cout<<"ERROR::LUA::TIMELINE::"<<file<<endl;
  }else{
    int n=file.find_last_of("/\\")+1;
    int m=file.find_last_of(".");    
    if(lua_istable(L,-1)){
      name=file.substr(n,m-n);
      lua_pushnil(L);
      while(lua_next(L,-2)!=0){
	nodes.push_back({action(getaction(L),L),(uint)getnumeric(L,"n")});
	lua_pop(L,1);
      }
    }
  }
}
void ctimeline::toggle(){
  running=!running;
}
