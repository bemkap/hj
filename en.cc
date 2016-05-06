#include<GL/glew.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include"en.hh"
#include"ut.hh"

en::en():quit(false){
  for(int i=0;i<256;++i) kst[i]=NPR;
  pst.le=pst.ri=NPR;
}
en::~en(){}
//
void en::disp(){
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  for(auto i:obs)
    for(auto j:i->ins)
      if(i->spr) i->spr->disp(j->x,j->y,j->xsc,j->ysc);
  glutSwapBuffers();
}
void en::resh(int we,int he){
  w=we;h=he;
  glViewport(0,0,(GLsizei)we,(GLsizei)he);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  glMatrixMode(GL_MODELVIEW);
}
void en::eupd(){
  for(auto i:obs) i->oupd();
  for(int i=0;i<256;++i) if(kst[i]==RE) kst[i]=NPR;
  if(pst.le==RE) pst.le=NPR;
  if(pst.ri==RE) pst.ri=NPR;
}
en&eget(){
  static en env;
  return env;
}
