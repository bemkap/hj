#include<GL/glew.h>
#include"sp.hh"

sp::sp(initializer_list<point> l):msk(l),c({1,1,1}){}
poly sp::smget(double x,double y,double xsc,double ysc){poly rmsk;
  for(auto i:msk.pts)
    rmsk.ppadd({i.x*xsc+x,i.y*ysc+y});
  return rmsk;
}
void sp::disp(double x,double y,double xsc,double ysc){
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(c.r,c.g,c.b);
  for(auto i:msk.pts)
    glVertex2f(i.x*xsc+x,i.y*ysc+y);
  glEnd();
  glPopMatrix();
}
