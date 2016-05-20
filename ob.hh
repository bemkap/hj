#pragma once

#include<map>
#include<vector>
#include"cm.hh"
#include"in.hh"
#include"ev.hh"
#include"sp.hh"
#include"tl.hh"

class ob {public:
  map<uchar,act> kbh;
  map<ptbtn,act> pth;
  map<uint ,act> coh;
  act*crte,*step,*dest,*alrm[11];
  vector<in*> ins;
  sp*spr;
  tl*tline;
  ob(sp*);ob();~ob();
  void app(uchar);
  void app(ptbtn);
  void app(uint );
  void oidel(in*);
  in*  oiadd(double,double);
  in*  operator[](uint);
  void oupd();
  void disp(double,double,double,double);
};
