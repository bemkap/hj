#include"ev.hh"

ehdl::ehdl(lua_State*M):L(M){}
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

ecrt::ecrt(lua_State*L):ehdl(L){}
estp::estp(lua_State*L):ehdl(L){}
ealr::ealr(lua_State*L):ehdl(L){}
edes::edes(lua_State*L):ehdl(L){}
eptd::eptd(lua_State*L):ehdl(L){}
eptu::eptu(lua_State*L):ehdl(L){}
ekbd::ekbd(lua_State*L):ehdl(L){}
ecol::ecol(lua_State*L):ehdl(L){}

ev::~ev(){
  if(crte) delete crte;
  if(step) delete step;
  if(alrm) delete alrm;
  if(dest) delete dest;
  if(kbdo) delete kbdo;
  if(ptdo) delete ptdo;
  if(ptup) delete ptup;
  if(coll) delete coll;
}
