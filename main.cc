#include"main.hh"

en&env=eget();

void display(){env.disp();}
void timer(int v){env.eupd();glutTimerFunc(uint(1000/FPS),timer,v);}
void reshape(int w,int h){env.resh(w,h);}
void keyboard(uchar k,int x,int y){env.kst[k]=PR;}
void keyboaru(uchar k,int x,int y){env.kst[k]=RE;}
void mouse(int x,int y){env.pst.x=x;env.pst.y=env.h-y;}
void mousebtn(int b,int st,int x,int y){switch(b){
  case GLUT_LEFT_BUTTON : {env.pst.le=(st==GLUT_UP)?RE:PR;break;}
  case GLUT_RIGHT_BUTTON: {env.pst.ri=(st==GLUT_UP)?RE:PR;break;}
  }
}

void init(int*argc,char**argv){
  glutInit(argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(240,480);
  env.w=240;env.h=480;
  glutCreateWindow("OpenGL");
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(uint(1000/FPS),timer,0);
  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboaru);
  glutMotionFunc(mouse);
  glutMouseFunc(mousebtn);
  glutPassiveMotionFunc(mouse);
  glutSetCursor(GLUT_CURSOR_NONE);
}

int main(int argc,char**argv){
  init(&argc,argv);
  loadsps();
  loadobs();
  //tl dec
  tline*tl0=new tline;
  tl0->tladd(  1,[](in*i){i->dir=60;i->spe=40;i->fr=4;});
  tl0->tladd( 11,[](in*i){i->fr=0;});
  tl0->tladd( 20,[](in*i){i->hsp=4;i->alrn[0]=10;i->alrn[1]=3;});
  tl0->tladd(100,[](in*i){i->alrn[1]=0;i->alrn[2]=1;});
  OGET(env,"enem")->tl=tl0;
  //ins dec/def
  OGET(env,"worl")->oiadd(0,0);
  in*ship0=OGET(env,"ship")->oiadd(0,0);
  ship0->xsc=ship0->ysc=2;
  OGET(env,"enem")->oiadd(50,300);
  glutMainLoop();
  return 0;
}
