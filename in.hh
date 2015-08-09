#ifndef IN_HH
#define IN_HH

#include<list>
using namespace std;

class in {public:
  float x,y,sp,di,vsp,hsp;
  in(float,float);
  void move();
};

typedef list<in*>::iterator IIT;

#endif
