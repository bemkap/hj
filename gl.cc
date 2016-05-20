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
void keyboard(uchar k,int x,int y){env.kbobs[k].sign(k);}
void skeyboard(int k,int x,int y){env.kbobs[k+127].sign(k);}
void keyboaru(uchar k,int x,int y){env.kbobs[k].sign(k);}
void skeyboaru(int k,int x,int y){env.kbobs[k+127].sign(k);}
void mouse(int x,int y){}
void mousebtn(int b,int st,int x,int y){switch(b){
  case GLUT_LEFT_BUTTON : {env.ptobs[0].sign(PT_LE);break;};
  case GLUT_RIGHT_BUTTON: {env.ptobs[1].sign(PT_RI);break;}
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
