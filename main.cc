#include"main.hh"

en&env=eget();

void display(){env.disp();}
void timer(int v){env.eupd();glutTimerFunc(uint(1000/FPS),timer,v);}
void reshape(int w,int h){env.resh(w,h);}
void keyboard(uchar k,int x,int y){env.kst[k]=PR;}
void keyboaru(uchar k,int x,int y){env.kst[k]=RE;}
void mouse(int x,int y){env.pst.x=x;env.pst.y=env.h-y;}
void mousebtn(int b,int st,int x,int y){switch(b){
  case GLUT_LEFT_BUTTON : env.pst.le=(st==GLUT_UP)?RE:PR;break;
  case GLUT_RIGHT_BUTTON: env.pst.ri=(st==GLUT_UP)?RE:PR;break;
  }
}

void tri_kbd_up(in*i){i->vsp= 3;}
void tri_kbd_do(in*i){i->vsp=-3;}
void tri_kbd_le(in*i){i->hsp=-3;}
void tri_kbd_ri(in*i){i->hsp= 3;}
void tri_kbd_hs(in*i){i->hsp= 0;}
void tri_kbd_vs(in*i){i->vsp= 0;}
void wor_kbd_es(in*i){exit(0);}
void bul_stp   (in*i){if(i->x>env.w||i->x<0||i->y>env.h||i->y<0){
    ob*o=env.eoget(env.eoiget("obul"));
    o->oidel(i);
  }
}
void tri_ptr_le(in*i){ob*o=env.eoget(env.eoiget("obul"));
  if(o){
    in*j=o->oiadd(i->x,i->y);
    j->spe=6;
    j->dir=radtodeg(point_direction(i->x,i->y,env.pst.x,env.pst.y));
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
  sp*stri=new sp({{0,0},{3,0},{3,3}});
  sp*sbul=new sp({{0,0},{1,0},{1,1},{0,1}});
  env.esadd("stri",stri);
  env.esadd("sbul",sbul);
  //obs dec
  ob*owor=new ob;
  ob*otri=new ob;
  ob*obul=new ob;
  env.eoadd("owor",owor);
  env.eoadd("otri",otri);
  env.eoadd("obul",obul);
  //obs spr
  otri->spr=stri;
  obul->spr=sbul;
  //obs ev
  obul->oeadd(STEP,bul_stp);
  owor->oeadd(KBDO,wor_kbd_es,'q');
  otri->oeadd(KBDO,tri_kbd_up,',');
  otri->oeadd(KBDO,tri_kbd_do,'o');
  otri->oeadd(KBDO,tri_kbd_le,'a');
  otri->oeadd(KBDO,tri_kbd_ri,'e');
  otri->oeadd(KBUP,tri_kbd_vs,',');
  otri->oeadd(KBUP,tri_kbd_vs,'o');
  otri->oeadd(KBUP,tri_kbd_hs,'a');
  otri->oeadd(KBUP,tri_kbd_hs,'e');
  otri->oeadd(PTDO,tri_ptr_le,BTN_LE);
  //ins dec/def
  otri->oiadd(100,100);
  owor->oiadd(0,0);
  
  glutMainLoop();
  return 0;
}
