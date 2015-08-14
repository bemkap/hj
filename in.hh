#ifndef IN_HH
#define IN_HH

#include<vector>
#include"cm.hh"
using namespace std;

class in {public:
  float x,y,sp,di,vsp,hsp;
  float xsc,ysc;
  bool del;
  uint tlcurt;
  vector<node>::iterator tlcurn; //cuidado
  in(float,float);
  void move();
};

#endif
