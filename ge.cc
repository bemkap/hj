#include"ge.hh"
#include"cm.hh"

point::point(float x,float y):x(x),y(y){}
line::line(point p,point q):p(p),q(q){}
line::line(float px,float py,float qx,float qy):p(point(px,py)),q(point(qx,qy)){}
void poly::ppadd(point p){
  pts.push_back(p);
}
void poly::ppadd(float px,float py){
  ppadd(point(px,py));
}
bool left(point p,line l){
  return (l.q.x-l.p.x)*(p.y-l.p.y)>=(l.q.y-l.p.y)*(p.x-l.p.x);
}
bool intersect(point p,poly q){
  bool c=true;
  for(uint i=0;c&&i<q.pts.size();i+=2){
    line l(q.pts[i],q.pts[(i+1)%q.pts.size()]);
    c=c&&left(p,l);
  }
  return c;
}
bool intersect(poly p,poly q){
  bool c=false;
  for(uint i=0;!c&&i<p.pts.size();++i)
    c=c||intersect(p.pts[i],q);
  return c;
}
