#pragma once

#include<GL/glew.h>
#include<string>
#include"instance.hh"
using namespace std;

class csprite {
public:
  GLuint vao,vertexvbo,texturevbo,ebo,tex;
  string name;
  uint frames;
  GLfloat fwidth,fheight,fspeed;
  csprite(string);
  void display(GLuint,GLfloat&);
  void display(GLuint,float,float);
};
