#include<GL/glew.h>
#include"sprite.hh"

csprite::csprite(){}//initializer_list<point> l):mask(l),color({1,1,1}){}
void csprite::display(double x,double y,double xsc,double ysc){
  glBufferData(GL_ARRAY_BUFFER,size,vertices,GL_STATIC_DRAW);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),(GLvoid*)0);
  glEnableVertexAttribArray(0);
  /*
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(color.r,color.g,color.b);
  for(auto i:mask.points)
    glVertex2f(i.x*xsc+x,i.y*ysc+y);
  glEnd();
  glPopMatrix();
  */
}
