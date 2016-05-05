#include<GL/glew.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include"en.hh"
#include"ut.hh"

en::en():oav(0),sav(0),quit(false){
  for(int i=0;i<256;++i) kst[i]=NPR;
  pst.le=pst.ri=NPR;
}
en::~en(){
  for(auto i:obs) delete i;
  for(auto i:sps) delete i;
}
//obs
void en::eoadd(string n,ob*o){
  obs.push_back(o);
  oids.insert(pair<string,obid>(n,oav++));
}
ob*en::eoget(obid n){
  return n<obs.size()?obs[n]:nullptr;
}
obid en::eoiget(string n){
  MOIT i;
  if((i=oids.find(n))!=oids.end()) return (*i).second;
  else return -1;
}
//sps
void en::esadd(string n,sp*s){
  sps.push_back(s);
  sids.insert(pair<string,spid>(n,sav++));
}
sp*en::esget(spid n){
  return n<sps.size()?sps[n]:nullptr;
}
spid en::esiget(string n){
  MSIT i;
  if((i=sids.find(n))!=sids.end()) return (*i).second;
  else return -1;
}
//
void en::disp(){
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  for(auto i:obs)
    for(auto j:i->ins)
      if(i->spr) i->spr->disp(j->x,j->y,j->xsc,j->ysc);
  glutSwapBuffers();
}
void en::resh(int we,int he){
  w=we;h=he;
  glViewport(0,0,(GLsizei)we,(GLsizei)he);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  glMatrixMode(GL_MODELVIEW);
}
void en::eupd(){
  for(auto i:obs) i->oupd();
  for(int i=0;i<256;++i) if(kst[i]==RE) kst[i]=NPR;
  if(pst.le==RE) pst.le=NPR;
  if(pst.ri==RE) pst.ri=NPR;
}
en&eget(){
  static en env;
  return env;
}
void loadsps(){
  en&env=eget();
  env.esadd("sp0",new sp({{0,0},{5,0},{5,5}}));
  env.esadd("sp1",new sp{{0,0},{8,0},{8,8},{0,8}});
}
static ob*defworl(){
  ob*worl=new ob;
  worl->oeadd(KBDO,'q',[](in*i){exit(0);});
  return worl;
}
static ob*defship(){
  en&env=eget();
  ob*ship=new ob(SGET(env,"sp0"));
  ship->oeadd(STEP,[](in*i){i->x=eget().pst.x;i->y=eget().pst.y;});
  ship->oeadd(COLL,env.eoiget("bull"),[](in*i){i->st=DEAD;});
  ship->oeadd(COLL,env.eoiget("enem"),[](in*i){i->st=DEAD;});
  return ship;
}
static ob*defbull(){
  ob*bull=new ob(SGET(eget(),"sp1"));
  bull->oeadd(STEP,[](in*i){
      if(i->x>eget().w||i->x<0||i->y>eget().h||i->y<0)
	i->st=DEAD;
    });
  return bull;
}
static ob*defenem(){
  ob*enem=new ob(SGET(eget(),"sp1"));
  enem->oeadd(ALRM,0,[](in*i){i->hsp*=-1;i->alrn[0]=40;});
  enem->oeadd(ALRM,1,[](in*i){
      en&env=eget();
      in*ship0=(*env.eoget(env.eoiget("ship")))[0];
      double nx=i->x+arb(100)-50,ny=i->y+arb(100)-50;
      REPEAT(3){
	in*bull0=env.eoget(env.eoiget("bull"))->oiadd(nx,ny);
	if(ship0) bull0->dir=radtodeg(point_direction(nx,ny,ship0->x,ship0->y));
	bull0->spe=arb(8)+4;
      }
      i->alrn[1]=3;
    });
  enem->oeadd(ALRM,2,[](in*i){});
  return enem;
}
void loadobs(){
  en&env=eget();
  env.eoadd("worl",defworl());
  env.eoadd("ship",defship());
  env.eoadd("bull",defbull());  
  env.eoadd("enem",defenem());
}
