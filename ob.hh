#pragma once

#include<deque>
#include<vector>
#include"cm.hh"
#include"in.hh"
#include"ev.hh"
#include"sp.hh"
#include"tl.hh"

class ob {public:
  vector<ev*> evs;
  deque<in*> ins;
  sp*spr;
  tline*tl;
  ob();ob(sp*);~ob();
  void oeadd(evt,act);       // step
  void oeadd(evt,uint,act);  // coll/alrm/kbd[o/u]
  void oeadd(evt,ptbtn,act); // mouse
  in*  oiadd(float,float);
  void oupd();
};
