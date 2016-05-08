#include<GL/glew.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include"en.hh"
#include"di.hh"
#include"ut.hh"

static bool insight(in*i,ro*r){
  return i->x>r->vpx&&i->y>r->vpy&&
    i->x<r->vpx+r->vpw&&i->y<r->vpy+r->vph;
}
en::en():curo(nullptr),quit(false){
  for(int i=0;i<256;++i) kst[i]=NPR;
  pst.le=pst.ri=NPR;
}
en::~en(){}
void en::disp(){
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  for(auto i:obs.obs)
    for(auto j:i->ins)
      if(i->spr){
	if(!curo) i->spr->disp(j->x,j->y,j->xsc,j->ysc);
	else if(insight(j,curo))
	  i->spr->disp(j->x-curo->vpx,j->y-curo->vpy,j->xsc,j->ysc);
      }
  glutSwapBuffers();
}
void en::resh(int we,int he){
  if(curo){
    curo->w*=we/curo->vpw;
    curo->h*=he/curo->vph;
    curo->vpw=we;
    curo->vph=he;
  }
  glViewport(0,0,(GLsizei)we,(GLsizei)he);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,we,0,he);
  glMatrixMode(GL_MODELVIEW);
}
void en::eupd(){
  for(auto i:obs.obs) i->oupd();
  for(int i=0;i<256;++i) if(kst[i]==RE) kst[i]=NPR;
  if(pst.le==RE) pst.le=NPR;
  if(pst.ri==RE) pst.ri=NPR;
}
void en::swro(string r){ro*nro=ros.get(r);
  if(nro!=curo){
    for(auto i:obs.obs)
      for(auto j:i->ins)
	j->st=DEAD;
    nro->disp();
    curo=nro;
    glutReshapeWindow(curo->vpw,curo->vph);
  }
}
en&eget(){static en env;
  return env;
}
