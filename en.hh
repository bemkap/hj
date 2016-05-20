#pragma once

#include<map>
#include<vector>
#include<string>
#include"cm.hh"
#include"di.hh"
#include"ob.hh"
#include"ro.hh"
#include"sp.hh"
#include"tl.hh"
#include"wa.hh"
using namespace std;

class en {public:
  en();
  dict<ob> obs;
  dict<sp> sps;
  dict<tl> tls;
  dict<ro> ros;ro*curo;
  //observer
  wa<uchar> kbobs[256];
  wa<ptbtn> ptobs[  2];
  //
  bool quit;
  void disp();
  void resh(int,int);
  void eupd();
  void swro(string);
};

en&eget();
