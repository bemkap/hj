#ifndef TL_HH
#define TL_HH

#include<vector>
#include"ev.hh"
using namespace std;

typedef struct { act a;uint step; } node;

class tline {public:
  vector<node> nds;
  bool st;
  tline();
  void tladd(act,uint);
  void tltog();
};

#endif
