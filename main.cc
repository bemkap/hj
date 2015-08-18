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
  glutCreateWindow("hj");
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(uint(1000/FPS),timer,0);
  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboaru);
  glutMotionFunc(mouse);
  glutMouseFunc(mousebtn);
  glutPassiveMotionFunc(mouse);
}

int main(int argc,char**argv){
  init(&argc,argv);
  //sps dec
  sp*stri=new sp({{0,0},{3,0},{3,3}});      env.esadd("stri",stri);
  sp*sbul=new sp({{0,0},{1,0},{1,1},{0,1}});env.esadd("sbul",sbul);
  //obs dec
  ob*owor=new ob;      env.eoadd("owor",owor);
  ob*otri=new ob(stri);env.eoadd("otri",otri);
  ob*obul=new ob(sbul);env.eoadd("obul",obul);
  ob*osqr=new ob(sbul);env.eoadd("osqr",osqr);
  //obs ev
  obul->oeadd(STEP,[](in*i){if(i->x>env.w||i->x<0||i->y>env.h||i->y<0){
	ob*o=env.eoget(env.eoiget("obul"));
	o->oidel(i);
      }
    });
  owor->oeadd(KBDO,'q',[](in*i){exit(0);});
  otri->oeadd(KBDO,',',[](in*i){i->vsp= 3;});
  otri->oeadd(KBDO,'o',[](in*i){i->vsp=-3;});
  otri->oeadd(KBDO,'a',[](in*i){i->hsp=-3;});
  otri->oeadd(KBDO,'e',[](in*i){i->hsp= 3;});
  otri->oeadd(KBUP,',',[](in*i){i->vsp= 0;});
  otri->oeadd(KBUP,'o',[](in*i){i->vsp= 0;});
  otri->oeadd(KBUP,'a',[](in*i){i->hsp= 0;});
  otri->oeadd(KBUP,'e',[](in*i){i->hsp= 0;});
  otri->oeadd(PTDO,BTN_LE,[](in*i){ob*o=env.eoget(env.eoiget("obul"));
      if(o){
	in*j=o->oiadd(i->x,i->y);
	j->spe=6;
	j->dir=radtodeg(point_direction(i->x,i->y,env.pst.x,env.pst.y));
      }
    });
  otri->oeadd(COLL,env.eoiget("osqr"),[](in*i){i->del=true;});
  osqr->oeadd(ALRM,40,[](in*i){i->hsp*=-1;});
  //ins dec/def
  otri->oiadd(100,100);
  owor->oiadd(0,0);
  in*sqr0=osqr->oiadd(50,300);
  sqr0->hsp=4;
  sqr0->xsc=sqr0->ysc=5;
  
  glutMainLoop();
  return 0;
}
