#include<GL/glew.h>
#include"sprite.hh"

csprite::csprite(initializer_list<point> l):msk(l),c({1,1,1}){}
polygon csprite::maskget(double x,double y,double xsc,double ysc){
  polygon maskret;
  for(auto i:mask.points)
    maskret.pointadd({i.x*xsc+x,i.y*ysc+y});
  return maskret;
}
void csprite::display(double x,double y,double xsc,double ysc){
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(c.r,c.g,c.b);
  for(auto i:mask.points)
    glVertex2f(i.x*xsc+x,i.y*ysc+y);
  glEnd();
  glPopMatrix();
}
