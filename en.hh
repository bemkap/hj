#pragma once

#include<map>
#include<vector>
#include<string>
#include"cm.hh"
#include"ob.hh"
#include"sp.hh"
using namespace std;

enum st { PR,RE,NPR };
struct ptr { int x,y;st le,ri; };

class en {public:
  en();~en();
  //obs
  vector<ob*> obs;
  map<string,obid> oids;
  obid oav;
  void eoadd(string,ob*);
  ob*  eoget(obid);
  obid eoiget(string);
  //sps
  vector<sp*> sps;
  map<string,spid> sids;
  spid sav;
  void esadd(string,sp*);
  sp*  esget(spid);
  spid esiget(string);
  //keys,mouse
  st kst[256];
  ptr pst;
  //win
  int w,h;
  //
  bool quit;
  void disp();
  void resh(int,int);
  void eupd();
};

en&eget();
  
typedef map<string,obid>::iterator MOIT;
typedef map<string,spid>::iterator MSIT;
