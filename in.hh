#ifndef IN_HH
#define IN_HH

#include<deque>
using namespace std;

class in {public:
  float x,y,sp,di,vsp,hsp;
  bool del;
  in(float,float);
  void move();
};

typedef deque<in*>::iterator IIT;

#endif
