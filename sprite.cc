#include<GL/glew.h>
#include"sprite.hh"

csprite::csprite():size(0){
  glGenBuffers(1,&vbo);
  glGenVertexArrays(1,&vao);
}
void csprite::bind(){
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER,vbo);
  glBufferData(GL_ARRAY_BUFFER,size,vertices,GL_STATIC_DRAW);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),(GLvoid*)0);
  glEnableVertexAttribArray(0);
  glBindVertexArray(0);
}
void csprite::display(double x,double y,double xsc,double ysc){
  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES,0,size/sizeof(GLfloat));
  glBindVertexArray(0);
}
