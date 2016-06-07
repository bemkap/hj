#pragma once

#include<GL/glew.h>
#include<string>
using namespace std;

class csprite {
public:
  GLuint vao,vertexvbo,texturevbo,ebo,tex;
  string name;
  int frames,current;
  int fwidth,fheight;
  csprite(string);
  void display();
};
