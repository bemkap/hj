#include<iostream>
#include<GL/glew.h>
#include<GL/glu.h>
#include<GL/glut.h>

#include"common.hh"
#include"env.hh"
#include"gl.hh"

static env&env=envget();

void display(){env.display();}
void timer(int v){
  if(!env.quit){
    env.update();
    glutTimerFunc(uint(1000/FPS),timer,v);
  }
  else exit(0);
}
void reshape(int w,int h){env.reshape(w,h);}
void keyboard(uchar k,int x,int y){env.watcherkb[k].signal(k);}
void skeyboard(int k,int x,int y){env.watcherkb[k+127].signal(k);}
void keyboaru(uchar k,int x,int y){env.watcherkb[k].signal(k);}
void skeyboaru(int k,int x,int y){env.watcherkb[k+127].signal(k);}
void mouse(int x,int y){}
void mousebtn(int b,int st,int x,int y){
  switch(b){
  case GLUT_LEFT_BUTTON : env.watchermouse[0].signal(PT_LE);break;
  case GLUT_RIGHT_BUTTON: env.watchermouse[1].signal(PT_RI);break;
  }
}
void init(int*argc,char**argv){
  glutInit(argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(240,480);
  glutCreateWindow("OpenGL");
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(uint(1000/FPS),timer,0);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(skeyboard);
  glutKeyboardUpFunc(keyboaru);
  glutSpecialUpFunc(skeyboaru);
  glutMotionFunc(mouse);
  glutMouseFunc(mousebtn);
  glutPassiveMotionFunc(mouse);
  glutSetCursor(GLUT_CURSOR_NONE);
}
