#pragma once

#include<lua5.2/lua.hpp>
#include"common.hh"
#include"dict.hh"
#include"object.hh"
#include"room.hh"
#include"sprite.hh"
#include"timeline.hh"
#include"watcher.hh"
using namespace std;

class env {
public:
  env();
  dict<object> objects;
  dict<csprite> sprites;
  dict<ctimeline> timelines;
  dict<room> rooms;room*currentroom;
  //watcher
  watcher<uchar> watcherkb[256];
  watcher<ptbutton> watchermouse[2];
  //script
  scriptmng scriptmng;
  //
  void init();
  bool quit;
  void display();
  void reshape(int,int);
  void update();
  void switchroom(string);
};

env&envget();
