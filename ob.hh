#ifndef OB_HH
#define OB_HH

#include<deque>
#include<vector>
#include"cm.hh"
#include"in.hh"
#include"ev.hh"
#include"sp.hh"

class ob {public:
  vector<ev*> evs;
  deque<in*> ins;
  sp*spr;
  ob();
  void oeadd(evt,act);       // step
  void oeadd(evt,act,uint);  // coll/alrm/kbd[o/u]
  void oeadd(evt,act,ptbtn); // mouse
  IIT  oiadd(float,float);
  void oidel(IIT);
  void oupd();
  ~ob();
};

typedef vector<ob*>::iterator OIT;

#endif
