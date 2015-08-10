#include<GL/glew.h>
#include"sp.hh"

sp::sp():r(1),g(1),b(1){}
sp::sp(float r,float g,float b):r(r),g(g),b(b){}
void sp::spadd(float px,float py){
  msk.ppadd(px,py);
}
poly sp::smget(float x,float y){
  poly rmsk=msk;
  for(PIT i=msk.pts.begin();i!=msk.pts.end();++i){
    (*i).x+=x;
    (*i).y+=y;
  }
  return rmsk;
}
void sp::disp(float x,float y){
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(r,g,b);
  for(PIT i=msk.pts.begin();i!=msk.pts.end();++i)
    glVertex2f((*i).x+x,(*i).y+y);
  glEnd();
  glPopMatrix();
}
