#include<GL/glew.h>
#include"sp.hh"

sp::sp():r(1),g(1),b(1){}
void sp::spcol(float rr,float gg,float bb){
  r=rr;
  g=gg;
  b=bb;
}
void sp::spadd(float px,float py){
  msk.ppadd(px,py);
}
poly sp::smget(float x,float y,float xsc,float ysc){
  poly rmsk;
  for(auto i:msk.pts)
    rmsk.pts.push_back(point(i.x*xsc+x,i.y*ysc+y));
  return rmsk;
}
void sp::disp(float x,float y,float xsc,float ysc){
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(r,g,b);
  for(auto i:msk.pts)
    glVertex2f(i.x*xsc+x,i.y*ysc+y);
  glEnd();
  glPopMatrix();
}
