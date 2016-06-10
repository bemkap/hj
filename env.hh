#pragma once

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<lua5.2/lua.hpp>
#include"common.hh"
#include"dict.hh"
#include"graphicmng.hh"
#include"object.hh"
#include"room.hh"
#include"sprite.hh"
#include"timeline.hh"
#include"watcher.hh"
using namespace std;

class env {
private:
  env();~env();
public:
  dict<object> objects;
  dict<ctimeline> timelines;
  dict<room> rooms;room*currentroom;
  //watcher
  watcher<uchar> watcherkbdo[256];
  watcher<uchar> watcherkbup[256];
  watcher<ptbutton> watchermousedo[2];
  watcher<ptbutton> watchermouseup[2];
  //graphics
  cgraphicmng graphicmng;
  //scripts
  lua_State*L;
  //
  void init();
  void close();
  bool quit;
  void display();
  void reshape(int,int);
  void update();
  void switchroom(string);
  instance*instancecreate(string,float,float);
  static env&envget();
};
//
void callbackkb(GLFWwindow*w,int,int,int,int);
