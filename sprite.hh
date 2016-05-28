#pragma once

#include<GL/glew.h>
#include<string>
#include"polygon.hh"
using namespace std;

struct rgb { double r,g,b; };

class csprite {
public:
  GLfloat*vertices;
  GLsizeiptr size;
  GLuint vao,vbo;
  rgb color;
  string name;
  csprite();
  void bind();
  void display(double,double,double,double);
};
