#pragma once

#include<GL/glew.h>
#include<string>
using namespace std;

class csprite {
public:
  GLsizeiptr size;
  GLuint vao,vbo,ebo,tex;
  string name;
  csprite();
  void bind(GLuint*,GLsizeiptr,GLfloat*,GLsizeiptr);
  void texture(string);
  void display(double,double,double,double);
};
