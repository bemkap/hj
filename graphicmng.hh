#pragma once

#include<GL/glew.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include"sprite.hh"

class cgraphicmng {
public:
  dict<csprite> sprites;
  cgraphicmng();~cgraphicmng();
  void loadspr();
  void clear();
  void reshape(GLsizei,GLsizei);
  void display(string,double,double,double,double);
  void flip();
};
