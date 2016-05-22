#pragma once

#include<vector>
using namespace std;

struct point { double x,y; };
struct line  { point  p,q; };

class polygon {
public:
  vector<point> points;
  polygon();
  polygon(initializer_list<point>);
  void pointadd(point);
};

bool left(point,line);
bool intersect(point,poly);
bool intersect(poly,poly);
