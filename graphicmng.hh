#pragma once

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#define GLM_FORCE_RADIANS
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"dict.hh"
#include"sprite.hh"
using namespace glm;

class cgraphicmng {
public:
  GLuint program;
  GLFWwindow*w;
  dict<csprite> sprites;
  vec3 camera;
  void init();
  void close();
  void loadspr();
  void clear();
  void reshape(GLsizei,GLsizei);
  void display(string,double,double);
  void flip();
};
