#include<GL/glew.h>
#include"sp.hh"

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
void sp::display(float x,float y){
  glPushMatrix();
  glBegin(GL_POLYGON);
  for(PIT i=msk.pts.begin();i!=msk.pts.end();++i)
    glVertex2f((*i).x+x,(*i).y+y);
  glEnd();
  glPopMatrix();
}
