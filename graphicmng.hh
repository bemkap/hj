#pragma once

#include<GL/glew.h>
#include<GLFW/glfw3.h>
//#include<GL/glu.h>
//#include<GL/glut.h>
#include"dict.hh"
#include"sprite.hh"

class cgraphicmng {
public:
  GLuint program;
  GLFWwindow*w;
  dict<csprite> sprites;
  void init();
  void close();
  void loadspr();
  void clear();
  void reshape(GLsizei,GLsizei);
  void display(string,double,double,double,double);
  void flip();
};
