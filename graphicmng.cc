#include<GL/glew.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include"common.hh"
#include"graphicmng.hh"

void loadspr(){}
void reshape(int w,int h){cgraphicmng::reshape(w,h);}
void cgraphicmng::cgraphimng(){
  glutInit(0,NULL);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(240,480);
  glutCreateWindow("OpenGL");
  glutReshapeFunc(reshape);
}
void cgraphicmng::clear(){
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
}
void cgraphicmng::reshape(GLsizei w,GLsizei h){
  glViewport(0,0,we,he);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,we,0,he);
  glMatrixMode(GL_MODELVIEW);
}
void cgraphicmng::display(string n,double x,double y,double xsc,double ysc){
  auto s=sprites.find(n);
  if(s!=sprites.end()) s->display(x,y,xsc,ysc);
}
void cgraphicmng::flip(){
  glutSwapBuffers();
}
