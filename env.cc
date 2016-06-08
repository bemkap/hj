#include<boost/filesystem.hpp>
#include"env.hh"
#include"event.hh"
#include"dict.hh"
#include"utils.hh"
using namespace boost::filesystem;
using namespace std;

env::env():currentroom(nullptr),quit(false){
  L=luaL_newstate();
  luaL_openlibs(L);
}
env::~env(){lua_close(L);}
void env::init(){
  path p("./OBJECTS");
  for(directory_iterator i(p);i!=directory_iterator();i++){
    object*o=new object((*i).path().string().c_str(),L);
    objects.add(o->name,o);
    for(auto e:o->handlerkb) watcherkb[e.first%256].watch(e.first%256,o);
    for(auto e:o->handlermouse) watchermouse[e.first].watch(e.first,o);
  }
  graphicmng.init();
  path q("./SPRITES");
  for(directory_iterator i(q);i!=directory_iterator();i++){
    if(csprite*s=new csprite((*i).path().string().c_str()))
      graphicmng.sprites.add(s->name,s);
  }
  glfwSetKeyCallback(graphicmng.w,callbackkb);
}
void env::close(){
  graphicmng.close();
}
void env::display(){
  graphicmng.clear();
  for(object*o:objects.entries)
    for(instance*i:o->instances)
      graphicmng.display(o->sprite,i->x,i->y,i->xscale,i->yscale);
  graphicmng.flip();
}
void env::reshape(int w,int h){
  if(currentroom) currentroom->reshape(w,h);
  graphicmng.reshape(w,h);
}
void env::update(){
  for(object*o:objects.entries) o->update();
}
void env::switchroom(string r){
  room*newroom=rooms.get(r);
  if(newroom!=currentroom){
    for(object*o:objects.entries)
      for(instance*i:o->instances) o->instancedestroy(i);
    newroom->display();
    currentroom=newroom;
    reshape(currentroom->viewportw,currentroom->viewporth);
  }
}
instance*env::instancecreate(string n,double x,double y){
  object*o=objects.get(n);
  return o?o->instancecreate(x,y):nullptr;
}
env&env::envget(){
  static env env;
  return env;
}
//
void callbackkb(GLFWwindow*w,int k,int sc,int a,int m){
  env::envget().watcherkb[k%256].signal(k%256);
}
