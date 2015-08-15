#ifndef GE_HH
#define GE_HH

#include<vector>
using namespace std;

struct point { float x,y; };

class line {public:
  point p,q;
  line(point,point);
};

class poly {public:
  vector<point> pts;
  poly();
  poly(initializer_list<point>);
  void ppadd(point);
};

bool left(point,line);
bool intersect(point,poly);
bool intersect(poly,poly);

#endif
