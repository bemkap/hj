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
  csprite(const string&);
  void display(GLuint,float&);
  void display(GLuint,float,float);
};
