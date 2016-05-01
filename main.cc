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
  sp*sp0=new sp({{0,0},{3,0},{3,3}});
  sp*sp1=new sp({{0,0},{5,0},{5,5},{0,5}});
  env.esadd("sp0",sp0);
  env.esadd("sp1",sp1);
  //tl dec
  tline*tl0=new tline;
  tl0->tladd( 1,[](in*i){i->dir=60;i->spe=40;i->fr=4;});
  tl0->tladd(11,[](in*i){i->fr=0;});
  tl0->tladd(20,[](in*i){i->hsp=4;i->alrn[0]=10;i->alrn[1]=3;});
  //obs dec
  ob*ob0=new ob;  
  ob*ob1=new ob(sp0);
  ob*ob2=new ob(sp1);
  ob*ob3=new ob(sp1);
  env.eoadd("ob0",ob0);
  env.eoadd("ob1",ob1);
  env.eoadd("ob2",ob2);  
  env.eoadd("ob3",ob3);
  //obs ev
  ob0->oeadd(KBDO,'q',[](in*i){exit(0);});
  ob1->oeadd(STEP,[](in*i){i->x=env.pst.x;i->y=env.pst.y;});
  ob1->oeadd(COLL,env.eoiget("ob3"),[](in*i){i->st=DEAD;});
  ob1->oeadd(COLL,env.eoiget("ob2"),[](in*i){i->st=DEAD;});
  ob2->oeadd(STEP,[](in*i){if(i->x>env.w||i->x<0||i->y>env.h||i->y<0)
	i->st=DEAD;
    });
  ob3->oeadd(ALRM,0,[](in*i){i->hsp*=-1;i->alrn[0]=40;});
  ob3->oeadd(ALRM,1,[](in*i){ob*ob2=env.eoget(env.eoiget("ob2"));
      in*ob20=ob2->oiadd(i->x,i->y);
      ob20->dir=rand(360);
      ob20->spe=rand(4)+4;
      i->alrn[1]=3;
    });
  ob3->tl=tl0;
  //ins dec/def
  ob0->oiadd(0,0);
  in*ob10=ob1->oiadd(0,0);
  ob10->xsc=ob10->ysc=2;
  ob3->oiadd(50,300);
  
  glutMainLoop();
  return 0;
}
