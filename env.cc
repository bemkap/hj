#include<GL/glew.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include"env.hh"
#include"event.hh"
#include"dict.hh"
#include"utils.hh"
using namespace std;

static void timer(int v){
  if(env.quit) exit(0);
  env.update();
  glutTimerFunc(uint(1000/FPS),timer,v);
}
static void keyboard(uchar k,int x,int y){env.watcherkb[k].signal(k);}
static void skeyboard(int k,int x,int y){env.watcherkb[k+127].signal(k);}
static void keyboaru(uchar k,int x,int y){env.watcherkb[k].signal(k);}
static void skeyboaru(int k,int x,int y){env.watcherkb[k+127].signal(k);}
static void mouse(int x,int y){}
static void mousebtn(int b,int st,int x,int y){
  switch(b){
  case GLUT_LEFT_BUTTON : env.watchermouse[0].signal(PT_LE);break;
  case GLUT_RIGHT_BUTTON: env.watchermouse[1].signal(PT_RI);break;
  }
}
/*
static inline bool insight(instance*i,room*r){
  return i->x>r->viewportx&&i->y>r->viewporty&&
    i->x<r->viewportx+r->viewportw&&i->y<r->viewporty+r->viewporth;
}
*/
env::env():currentroom(nullptr),quit(false){
  path p("./obs");
  for(directory_iterator i(p);i!=directory_iterator();i++){
    object*o=scriptmng.loadobj((*i).path().string().c_str());
    objects.add(o->name,o);
    for(auto e:o->handlerkb) watcherkb[*e].watch(*e,o);
    for(auto e:o->handlermouse) watchermouse[*e].watch(*e,o);
  }
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutTimerFunc(uint(1000/FPS),timer,0);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(skeyboard);
  glutKeyboardUpFunc(keyboaru);
  glutSpecialUpFunc(skeyboaru);
  glutMotionFunc(mouse);
  glutMouseFunc(mousebtn);
  glutPassiveMotionFunc(mouse);
  glutSetCursor(GLUT_CURSOR_NONE);
}
void env::display(){
  graphicmng.clear();
  for(object*o:objects.entries)
    for(instance*i:o->instances)
      graphicmng.display(o->sprite,
			 i->x-currentroom->viewportx,
			 i->y-currentroom->viewporty,
			 i->xscale,i->yscale,
			 currentroom);
  graphicmng.draw();
}
void env::reshape(int w,int h){
  if(currentroom) currentroom->reshape(w,h);
  graphicmng.reshape(w,h);
}
void env::update(){
  for(object*i:objects.entries) i->update();
}
void env::switchroom(string r){
  room*newroom=rooms.get(r);
  if(newroom!=currentroom){
    for(object*i:objects.entries)
      for(instance*j:i->instances) j->instancedelete();
    newroom->display();
    currentroom=newroom;
    reshape(currentroom->viewportw,currentroom->viewporth);
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
