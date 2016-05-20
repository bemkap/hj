#include"ev.hh"

act::act(int r,lua_State*L):r(r),L(L){}
int act::operator()(in*i){
  lua_rawgeti(L,LUA_REGISTRYINDEX,r);
  lua_pushstring(L,"i");lua_newuserdata(L,sizeof(in));
  return lua_pcall(L,1,0,0);
}
