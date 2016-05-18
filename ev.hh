#pragma once

#include<map>
#include<vector>
#include"cm.hh"
#include"in.hh"
using namespace std;

enum ptbtn { BTN_LE,BTN_RI };
enum evt { CRTE,KBDO,KBUP,PTDO,PTUP,STEP,COLL,ALRM,DEST };

class ehdl {public:lua_State*L;
  ehdl(lua_State*);
  virtual void add(){};
  virtual void operator()(in*){};
};
class ecrt:public ehdl {public: int r;
  ecrt(lua_State*);void operator()(in*);};
class estp:public ehdl {public: int r;
  estp(lua_State*);void operator()(in*);};
class ealr:public ehdl {public: int r[11];
  ealr(lua_State*);void operator()(in*,int);
  int  operator[](uint);};
class edes:public ehdl {public: int r;
  edes(lua_State*);void operator()(in*);};
class eptd:public ehdl {public: int r;
  eptd(lua_State*);void operator()(in*);};
class eptu:public ehdl {public: int r;
  eptu(lua_State*);void operator()(in*);};
class ekbd:public ehdl {public: map<uint,int> m;
  ekbd(lua_State*);void operator()(in*,uint);};
class ecol:public ehdl {public: map<uint,int> m;
  ecol(lua_State*);void operator()(in*,uint);};

class ev {public:
  ~ev();
  ecrt*crte;
  estp*step;
  ealr*alrm;
  edes*dest;
  ekbd*kbdo;
  eptd*ptdo;
  eptu*ptup;
  ecol*coll;
};
/*
typedef void (*act)(in*);

struct ecrt { evt ty;act a;         };
struct ekbd { evt ty;act a;uchar k; };
struct eptr { evt ty;act a;ptbtn b; };
struct estp { evt ty;act a;         };
struct ecol { evt ty;act a;uint n;  };
struct ealr { evt ty;act a;uint n;  };
struct edes { evt ty;act a;         };

union ev {
  evt ty;ecrt crt;ekbd kbd;eptr ptr;
  estp stp;ecol col;ealr alr;edes des;
};
*/
