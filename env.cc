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

static inline bool insight(instance*i,room*r){
  return i->x>r->viewportx&&i->y>r->viewporty&&
    i->x<r->viewportx+r->viewportw&&i->y<r->viewporty+r->viewporth;
}
env::env():currentroom(nullptr),quit(false){}
void env::init(){
  path p("./obs");
  for(directory_iterator i(p);i!=directory_iterator();i++){
    pair<string,object*> o=scriptmng.loadobj((*i).path().string().c_str());
    objects.add(o.first,o.second);
  }
}
void env::display(){
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  for(object*i:objects.entries)
    for(instance*j:i->instances)
      if(currentroom){
	if(insight(j,currentroom))
	  i->display(j->x-currentroom->viewportx,
		     j->y-currentroom->viewporty,
		     j->xscale,j->yscale);
	else
	  i->display(j->x,j->y,j->xscale,j->yscale);
      }
  glutSwapBuffers();
}
void env::reshape(int we,int he){
  if(currentroom){
    currentroom->width*=we/currentroom->viewportw;
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
instance*env::instancecreate(string n,double x,double y){
  object*o=objects.get(n);
  return o?o->instancecreate(x,y):nullptr;
}
env&envget(){
  static env env;
  return env;
}
