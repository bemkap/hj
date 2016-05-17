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
using namespace std;

enum st { PR,RE,NPR };
struct ptr { int x,y;st le,ri; };

class en {public:
  en();~en();
  dict<ob> obs;
  dict<sp> sps;
  //dict<tl> tls;
  dict<ro> ros;ro*curo;
  //keys,mouse
  st kst[256];
  ptr pst;
  //
  bool quit;
  void disp();
  void resh(int,int);
  void eupd();
  void swro(string);
};

en&eget();
