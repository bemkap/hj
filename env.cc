#include<boost/filesystem.hpp>
#include<GL/glew.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include"env.hh"
#include"event.hh"
#include"dict.hh"
#include"utils.hh"
using namespace boost::filesystem;
using namespace std;

static inline bool insight(in*i,ro*r){
  return i->x>r->vpx&&i->y>r->vpy&&
    i->x<r->vpx+r->vpw&&i->y<r->vpy+r->vph;
}
void parsekbdo(ob*o,lua_State*L){
  int r=getact(L);
  uchar k=getnum<uchar>(L,"key");
  o->kbh.insert(pair<uchar,act>(k,act(r,L)));
}
void parseptdo(ob*o,lua_State*L){
  int r=getact(L);
  ptbtn k=getnum<ptbtn>(L,"mouse");
  o->pth.insert(pair<ptbtn,act>(k,act(r,L)));
}
void parsestep(ob*o,lua_State*L){
  int r=getact(L);
  if(!o->step) o->step=new act(r,L);
  else{o->step->r=r;o->step->L=L;}
}
en::en():curo(nullptr),quit(false){}
void en::init(){
  path p("./obs");directory_iterator i(p);
  for(;i!=directory_iterator();i++){
    ob*o=sm.loadobj((*i).path().string().c_str());
    obs.add(path().string().c_str(),o);
  }
}
void en::disp(){
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  for(auto i:obs.obs)
    for(auto j:i->ins)
      if(insight(j,curo))
	i->disp(j->x-curo->vpx,j->y-curo->vpy,j->xsc,j->ysc);
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
}
void en::swro(string r){ro*nro=ros.get(r);
  if(nro!=curo){
    for(auto i:obs.obs)
      for(auto j:i->ins) i->oidel(j);
    nro->disp();
    curo=nro;
    glutReshapeWindow(curo->vpw,curo->vph);
  }
}
en&eget(){static en env;
  return env;
}
