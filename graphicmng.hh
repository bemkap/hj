#pragma once

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"dict.hh"
#include"instance.hh"
#include"sprite.hh"

class cgraphicmng {
public:
  GLuint program;
  GLFWwindow*window;
  int winwidth,winheight;
  float xcenter,ycenter;
  dict<csprite> sprites;
  void init();
  void close();
  void clear();
  void reshape(GLsizei,GLsizei);
  void setcamera();
  void flip();
};
