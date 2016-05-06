#pragma once

#include<vector>
#include"ev.hh"
using namespace std;

struct node { act a;uint step; };

class tl {public:
  vector<node> nds;
  bool st;
  tl();
  void tladd(uint,act);
  void tltog();
};
