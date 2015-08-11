#include<GL/glew.h>
#include"sp.hh"

sp::sp():r(1),g(1),b(1),xsc(1),ysc(1){}
void sp::spcol(float rr,float gg,float bb){
  r=rr;
  g=gg;
  b=bb;
}
void sp::spsc(float xxsc,float yysc){
  xsc=xxsc;
  ysc=yysc;
}
void sp::spadd(float px,float py){
  msk.ppadd(px,py);
}
poly sp::smget(float x,float y){
  poly rmsk;
  for(PIT i=msk.pts.begin();i!=msk.pts.end();++i)
    rmsk.pts.push_back(point((*i).x*xsc+x,(*i).y*ysc+y));
  return rmsk;
}
void sp::disp(float x,float y){
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(r,g,b);
  for(PIT i=msk.pts.begin();i!=msk.pts.end();++i)
    glVertex2f((*i).x*xsc+x,(*i).y*ysc+y);
  glEnd();
  glPopMatrix();
}
