#include<iostream>
#include<GL/glew.h>
#include<GL/glu.h>
#include<GL/glut.h>

#include"cm.hh"
#include"en.hh"
#include"gl.hh"

static en&env=eget();

void display(){env.disp();}
void timer(int v){
  if(!env.quit){env.eupd();glutTimerFunc(uint(1000/FPS),timer,v);}
  else{exit(0);}
}
void reshape(int w,int h){env.resh(w,h);}
void keyboard(uchar k,int x,int y){env.kst[k]=PR;}
void skeyboard(int k,int x,int y){env.kst[k+127]=PR;}
void keyboaru(uchar k,int x,int y){env.kst[k]=RE;}
void skeyboaru(int k,int x,int y){env.kst[k+127]=RE;}
void mouse(int x,int y){env.pst.x=x;env.pst.y=env.curo->vph-y;}
void mousebtn(int b,int st,int x,int y){switch(b){
  case GLUT_LEFT_BUTTON : {env.pst.le=(st==GLUT_UP)?RE:PR;break;}
  case GLUT_RIGHT_BUTTON: {env.pst.ri=(st==GLUT_UP)?RE:PR;break;}
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
