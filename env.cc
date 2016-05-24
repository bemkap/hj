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

static inline bool insight(in*i,room*r){
  return i->x>r->vpx&&i->y>r->vpy&&
    i->x<r->vpx+r->vpw&&i->y<r->vpy+r->vph;
}
env::env():currentroom(nullptr),quit(false){}
void env::init(){
  path p("./obs");
  for(directory_iterator i(p);i!=directory_iterator();i++){
    ob*o=scriptmng.loadobj((*i).path().string().c_str());
    objects.add(path().string().c_str(),o);
  }
}
void env::display(){
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  for(object*i:objects.entries)
    for(instance*j:i->instances)
      if(insight(j,currentroom))
	i->disp(j->x-currentroom->viewportx,
		j->y-currentroom->viewporty,
		j->xscale,j->yscale);
  glutSwapBuffers();
}
void env::reshape(int we,int he){
  if(currentroom){
    currentroom->weight*=we/currentroom->viewportw;
    currentroom->height*=he/currentroom->viewporth;
    currentroom->viewportw=we;
    currentroom->viewporth=he;
  }
  glViewport(0,0,(GLsizei)we,(GLsizei)he);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,we,0,he);
  glMatrixMode(GL_MODELVIEW);
}
void env::update(){
  for(object*i:objects.entries) i->update();
}
void env::switchroom(string r){
  room*newroom=rooms.get(r);
  if(newroom!=currentroom){
    for(object*i:objects.entries)
      for(instance*j:i->instances) i->instancedelete(j);
    newroom->display();
    currentroom=newroom;
    glutReshapeWindow(currentroom->viewportw,currentroom->viewporth);
  }
}
env&envget(){
  static env env;
  return env;
}
