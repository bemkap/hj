#pragma once

#include<vector>
#include"ev.hh"
using namespace std;

struct node { act a;uint step; };

class tline {public:
  vector<node> nds;
  bool st;
  tline();
  void tladd(uint,act);
  void tltog();
};
