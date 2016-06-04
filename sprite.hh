#pragma once

#include<GL/glew.h>
#include<lua5.2/lua.hpp>
#include<string>
using namespace std;

class csprite {
public:
  GLuint vao,vbo,ebo,tex;
  string name;
  csprite(const char*,lua_State*);
  void bind(GLfloat*);
  void texture(string);
  void display(double,double,double,double);
};
