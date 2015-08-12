#ifndef SP_HH
#define SP_HH

#include<vector>
#include"ge.hh"
using namespace std;

class sp {public:
  poly msk;
  float r,g,b;
  sp(); //initializer_list<float>);
  void spcol(float,float,float);
  void spadd(float,float);
  poly smget(float,float,float,float);
  void disp(float,float,float,float);
};

#endif
