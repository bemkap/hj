#include"ev.hh"

ehdl::ehdl(lua_State*M):L(M){}
ehdl::ehdl():ehdl(nullptr){}
void op1(lua_State*L,int r,in*i){
  lua_rawgeti(L,LUA_REGISTRYINDEX,r);
  lua_pushstring(L,"i");
  in*j=(in*)lua_newuserdata(L,sizeof(in));
  j->x=i->x;j->y=i->y;
  lua_pcall(L,1,0,0);
  i->x=j->x;i->y=j->y;
}
void ecrt::operator()(in*i){if(L&&r>0) op1(L,r,i);}
void estp::operator()(in*i){if(L&&r>0) op1(L,r,i);}
void ealr::operator()(in*i,int n){if(L&&r>0) op1(L,r[n],i);}
int  ealr::operator[](uint n){return r[n%11];}
void edes::operator()(in*i){if(L&&r>0) op1(L,r,i);}
void eptd::operator()(in*i){if(L&&r>0) op1(L,r,i);}
void eptu::operator()(in*i){if(L&&r>0) op1(L,r,i);}
void ekbd::operator()(in*i,uint n){map<uint,int>::iterator k;
  if((k=m.find(n))!=m.end()) op1(L,(*k).second,i);}
void ecol::operator()(in*i,uint n){map<uint,int>::iterator k;
  if((k=m.find(n))!=m.end()) op1(L,(*k).second,i);}
