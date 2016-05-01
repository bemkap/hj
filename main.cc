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
  //sps dec
  sp*sp0=new sp({{0,0},{5,0},{5,5}});
  sp*sp1=new sp({{0,0},{8,0},{8,8},{0,8}});
  env.esadd("sp0",sp0);
  env.esadd("sp1",sp1);
  //tl dec
  tline*tl0=new tline;
  tl0->tladd( 1,[](in*i){i->dir=60;i->spe=40;i->fr=4;});
  tl0->tladd(11,[](in*i){i->fr=0;});
  tl0->tladd(20,[](in*i){i->hsp=4;i->alrn[0]=10;i->alrn[1]=3;});
  //obs dec
  ob*worl=new ob;  
  ob*ship=new ob(sp0);
  ob*bull=new ob(sp1);
  ob*enem=new ob(sp1);
  env.eoadd("worl",worl);
  env.eoadd("ship",ship);
  env.eoadd("bull",bull);  
  env.eoadd("enem",enem);
  //obs ev
  worl->oeadd(KBDO,'q',[](in*i){exit(0);});
  ship->oeadd(STEP,[](in*i){i->x=env.pst.x;i->y=env.pst.y;});
  ship->oeadd(COLL,env.eoiget("bull"),[](in*i){i->st=DEAD;});
  ship->oeadd(COLL,env.eoiget("enem"),[](in*i){i->st=DEAD;});
  bull->oeadd(STEP,[](in*i){if(i->x>env.w||i->x<0||i->y>env.h||i->y<0)
	i->st=DEAD;
    });
  bull->oeadd(STEP,[](in*i){i->dir+=2;});
  enem->oeadd(ALRM,0,[](in*i){i->hsp*=-1;i->alrn[0]=40;});
  enem->oeadd(ALRM,1,[](in*i){
      in*ship0=env.eoget(env.eoiget("ship"))[0];
      ob*bull=env.eoget(env.eoiget("bull"));
      in*bull0=bull->oiadd(i->x,i->y);
      if(ship0) bull0->dir=point_direction(i->x,i->y,ship0->x,ship0->y);
      bull0->spe=rand(8)+4;
      i->alrn[1]=3;
    });
  enem->tl=tl0;
  //ins dec/def
  worl->oiadd(0,0);
  in*ship0=ship->oiadd(0,0);
  ship0->xsc=ship0->ysc=2;
  enem->oiadd(50,300);
  
  glutMainLoop();
  return 0;
}
