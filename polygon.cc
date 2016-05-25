#include"polygon.hh"

polygon::polygon(){}
polygon::polygon(initializer_list<point> list){
  for(auto i:list) points.push_back(i);
}
void polygon::ppadd(point p){
  points.push_back(p);
}
bool left(point p,line l){
  return (l.q.x-l.p.x)*(p.y-l.p.y)>=(l.q.y-l.p.y)*(p.x-l.p.x);
}
bool intersect(point p,polygon q){
  bool c=true;
  for(uint i=0;c&&i<q.points.size();++i)
    c=c&&left(p,{q.points[i],q.points[(i+1)%q.points.size()]});
  return c;
}
bool intersect(polygon p,polygon q){
  bool c=false;
  for(uint i=0;!c&&i<p.points.size();++i)
    c=c||intersect(p.points[i],q);
  return c;
}
