#ifndef SP_HH
#define SP_HH

#include<vector>
#include"ge.hh"
using namespace std;

class sp {public:
  poly msk;
  float r,g,b;
  float xsc,ysc;
  sp();
  void spcol(float,float,float);
  void spsc(float,float);
  void spadd(float,float);
  poly smget(float,float);
  void disp(float,float);
};

typedef vector<sp*>::iterator SIT;

#endif
