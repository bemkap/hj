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
    object*o=new object((*i).path().string().c_str(),L,graphicmng.sprites);
    objects.add(o->name,o);
    for(auto e:o->handlerkbdo) watcherkbdo[e.first].watch(e.first,o);
    for(auto e:o->handlerkbup) watcherkbup[e.first].watch(e.first,o);
    for(auto e:o->handlermousedo) watchermousedo[e.first].watch(e.first,o);
    for(auto e:o->handlermouseup) watchermouseup[e.first].watch(e.first,o);
  }
  graphicmng.init();
  path q("./SPRITES");
  for(directory_iterator i(q);i!=directory_iterator();i++){
    if(csprite*s=new csprite((*i).path().string().c_str()))
      graphicmng.sprites.add(s->name,s);
  }
  path r("./ROOMS");
  for(directory_iterator i(r);i!=directory_iterator();i++){
    if(room*r=new room((*i).path().string(),L))
      rooms.add(r->name,r);
  }
  glfwSetKeyCallback(graphicmng.window,callbackkb);
}
void env::close(){
  graphicmng.close();
}
void env::display(){
  graphicmng.clear();
  for(object*o:objects.entries)
    for(instance*i:o->instances)
      if(currentroom){
	currentroom->display(graphicmng.program);
	graphicmng.display(o->sprite,i,currentroom->viewportw,currentroom->viewporth);
      }else{
	graphicmng.display(o->sprite,i);
      }
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
    newroom->init();
    currentroom=newroom;
    reshape(currentroom->viewportw,currentroom->viewporth);
  }
}
instance*env::instancecreate(string n,float x,float y){
  object*o=objects.get(n);
  return o?o->instancecreate(x,y):nullptr;
}
env&env::envget(){
  static env env;
  return env;
}
//
void callbackkb(GLFWwindow*w,int k,int sc,int a,int m){
  switch(a){
  case GLFW_PRESS: env::envget().watcherkbdo[k%256].signal(k%256,(void*)true);break;
  case GLFW_RELEASE: env::envget().watcherkbup[k%256].signal(k%256,(void*)false);break;
  }
}
