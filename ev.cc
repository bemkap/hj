#include"ev.hh"

act::act(int r,lua_State*L):r(r),L(L){}
void act::operator()(in*i){
  lua_rawgeti(L,LUA_REGISTRYINDEX,r);
  lua_pushstring(L,"i");lua_newuserdata(L,sizeof(in));
  lua_pcall(L,0,0,0);
}
