#include"ge.hh"
#include"cm.hh"

poly::poly(){}
poly::poly(initializer_list<point> l){
  for(auto i:l) pts.push_back(i);
}
void poly::ppadd(point p){
  pts.push_back(p);
}
bool left(point p,line l){
  return (l.q.x-l.p.x)*(p.y-l.p.y)>=(l.q.y-l.p.y)*(p.x-l.p.x);
}
bool intersect(point p,poly q){bool c=true;
  for(uint i=0;c&&i<q.pts.size();++i)
    c=c&&left(p,{q.pts[i],q.pts[(i+1)%q.pts.size()]});
  return c;
}
bool intersect(poly p,poly q){bool c=false;
  for(uint i=0;!c&&i<p.pts.size();++i)
    c=c||intersect(p.pts[i],q);
  return c;
}
