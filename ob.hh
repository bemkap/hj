#pragma once

#include<deque>
#include<vector>
#include"cm.hh"
#include"in.hh"
#include"en.hh"
#include"ev.hh"
#include"sp.hh"
#include"tl.hh"

class ob {public:
  act[EVMX] evh;
  //vector<ev*> evs;
  deque<in*> ins;
  sp*spr;
  tl*tline;
  ob();ob(sp*);~ob();
  void oeadd(evt,act);       // step
  void oeadd(evt,uint,act);  // coll/alrm/kbd[o/u]
  void oeadd(evt,ptbtn,act); // mouse
  in*  oiadd(double,double);
  in*  operator[](uint);
  void oupd();
  void disp(double,double,double,double);
};
