#include<boost/filesystem.hpp>
#include"env.hh"
#include"event.hh"
#include"dict.hh"
#include"utils.hh"
using namespace boost::filesystem;

env::env():currentroom(nullptr),quit(false){
  L=luaL_newstate();
  luaL_openlibs(L);
}
env::~env(){lua_close(L);}
void env::init(){
  path p("./obs");
  for(directory_iterator i(p);i!=directory_iterator();i++){
    object*o=new object((*i).path().string().c_str(),L);
    objects.add(o->name,o);
    for(auto e:o->handlerkb) watcherkb[e.first%256].watch(e.first%256,o);
    for(auto e:o->handlermouse) watchermouse[e.first].watch(e.first,o);
  }
  graphicmng.init();
  path q("./sps");
  for(directory_iterator i(q);i!=directory_iterator();i++){
    csprite*s=new csprite((*i).path().string().c_str(),L);
    graphicmng.sprites.add(s->name,s);
  }
  path r("./rms");
  for(directory_iterator i(r);i!=directory_iterator();i++){
    room*r=new room((*i).path().string().c_str(),L);
    rooms.add(r->name,r);
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
  int width,height;
  double x,y;
  glfwGetFramebufferSize(graphicmng.w,&width,&height);
  glfwGetCursorPos(graphicmng.w,&x,&y);
  if(x>width-25){graphicmng.camera.x+=5;graphicmng.camera.y-=5;}
  else if(x<25){graphicmng.camera.x-=5;graphicmng.camera.y+=5;}
  if(y>height-25){graphicmng.camera.y+=5;graphicmng.camera.x+=5;}
  else if(y<25){graphicmng.camera.y-=5;graphicmng.camera.x-=5;}
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
env&envget(){
  static env env;
  return env;
}
//
void callbackkb(GLFWwindow*w,int k,int sc,int a,int m){
  envget().watcherkb[k%256].signal(k%256);
}
