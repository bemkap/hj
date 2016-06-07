#pragma once

#include<GL/glew.h>
#include<string>
using namespace std;

class csprite {
public:
  GLuint vao,vertexvbo,texturevbo,ebo,tex;
  string name;
  uint frames,current;
  uint fwidth,fheight;
  csprite(string);
  void display(GLuint);
};
