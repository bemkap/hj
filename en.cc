#include<GL/glew.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include"en.hh"

en::en():oav(0),sav(0){
  for(int i=0;i<256;++i) kst[i]=NPR;
  pst.le=NPR;pst.ri=NPR;
}
en::~en(){
  for(OIT i=obs.begin();i!=obs.end();++i) delete (*i);
  for(SIT i=sps.begin();i!=sps.end();++i) delete (*i);
}
//obs
void en::eoadd(string n,ob*o){
  obs.push_back(o);
  oids.insert(pair<string,obid>(n,oav++));
}
ob*en::eoget(obid n){
  if(n<(obid)obs.size()) return obs[n];
  else return NULL;
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
  if(n<(spid)sps.size()) return sps[n];
  else return NULL;
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
  for(OIT i=obs.begin();i!=obs.end();++i)
    for(IIT j=(*i)->ins.begin();j!=(*i)->ins.end();++j)
      if((*i)->spr!=NULL) (*i)->spr->display((*j)->x,(*j)->y);
  glutSwapBuffers();
}
void en::resh(int we,int he){
  glViewport(0,0,(GLsizei)we,(GLsizei)he);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  glMatrixMode(GL_MODELVIEW);
}
void en::eupd(){
  for(OIT i=obs.begin();i!=obs.end();++i) (*i)->oupd();
  for(int i=0;i<256;++i) if(kst[i]==RE) kst[i]=NPR;
  if(pst.le==RE) pst.le=NPR;
  if(pst.ri==RE) pst.ri=NPR;
}
en&eget(){
  static en env;
  return env;
}
