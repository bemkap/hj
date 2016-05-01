#pragma once

#include<vector>
#include"cm.hh"
using namespace std;

enum inst { BORN,LIVE,DEAD };

class in {public:
  float x,y;
  float spe,dir,vsp,hsp,gr,fr;
  float xsc,ysc;
  inst st;
  uint tlcurt,tlcurn;
  uint alrn[11];
  in(float,float);
  void move();
};
