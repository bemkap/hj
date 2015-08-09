#ifndef GE_HH
#define GE_HH

#include<vector>
using namespace std;

class point {public:
  float x,y;
  point(float,float);
};

class line {public:
  point p,q;
  line(point,point);
  line(float,float,float,float);
};

class poly {public:
  vector<point> pts;
  void ppadd(point);
  void ppadd(float,float);
};

bool left(point,line);
bool intersect(point,poly);
bool intersect(poly,poly);

typedef vector<point>::iterator PIT;

#endif
