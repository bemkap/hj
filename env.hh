#pragma once

#include"common.hh"
#include"dict.hh"
#include"graphicmng.hh"
#include"object.hh"
#include"room.hh"
#include"scriptmng.hh"
#include"sprite.hh"
#include"timeline.hh"
#include"watcher.hh"
using namespace std;

class env {
public:
  env();
  dict<object> objects;
  dict<ctimeline> timelines;
  dict<room> rooms;room*currentroom;
  //watcher
  watcher<uchar> watcherkb[256];
  watcher<ptbutton> watchermouse[2];
  //script
  cscriptmng scriptmng;
  //graphics
  cgraphicmng graphicmng;
  //
  void init();
  bool quit;
  void display();
  void reshape(int,int);
  void update();
  void switchroom(string);
  instance*instancecreate(string,double,double);
};
env&envget();
