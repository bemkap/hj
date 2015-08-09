#ifndef SP_HH
#define SP_HH

#include<vector>
#include"ge.hh"
using namespace std;

class sp {public:
  poly msk;
  void spadd(float,float);
  poly smget(float,float);
  void display(float,float);
};

typedef vector<sp*>::iterator SIT;

#endif
