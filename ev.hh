#pragma once

#include<lua5.2/lua.hpp>
#include<vector>
#include"cm.hh"
#include"in.hh"
#include"ob.hh"
using namespace std;

enum ptbtn { BTN_LE,BTN_RI };

class act {public:
  int r;lua_State*L;
  act(int,lua_State*);void operator()(in*);
};

class evmng {public:
  vector<ob*>[EVMX] obs;
  void signal(evty);
  void listen(evty,ob*);
};

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
