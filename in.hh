#ifndef IN_HH
#define IN_HH

#include<vector>
#include"cm.hh"
using namespace std;

class in {public:
  float x,y;
  float spe,dir,vsp,hsp,gr,fr;
  float xsc,ysc;
  bool del;
  uint tlcurt,tlcurn;
  uint alrn[11];
  in(float,float);
  void move();
};

#endif
