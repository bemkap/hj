#pragma once

#include<GL/glew.h>
#include<vector>
#include"polygon.hh"
using namespace std;

struct rgb { double r,g,b; };

class csprite {
public:
  GLfloat*vertices;
  GLsizeiptr size;
  //polygon mask;
  rgb color;
  csprite();//initializer_list<point>);
  void display(double,double,double,double);
};
