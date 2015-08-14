#ifndef TL_HH
#define TL_HH

#include<vector>
#include"ev.hh"
using namespace std;

struct node {
  act a;
  uint step;
};

class tline {public:
  vector<node> nds;
  bool st;
  tline();
  void tladd(act,uint);
  void tltog();
};

#endif
