#include<iostream>
#include<GL/glew.h>
#include<SOIL/SOIL.h>
#include<glm/glm.hpp>
#include"sprite.hh"
using namespace glm;

csprite::csprite(string file):current(0){
  //gen buffers
  glGenBuffers(1,&vertexvbo);
  glGenBuffers(1,&texturevbo);
  glGenVertexArrays(1,&vao);
  glGenBuffers(1,&ebo);
  glGenTextures(1,&tex);
  size_t n=file.find_last_of("/\\");
  size_t m=file.find_last_of(".");
  name=file.substr(n,m);
  frames=5;
  //create texture
  int w,h;
  unsigned char*img=SOIL_load_image(file,&w,&h,0,SOIL_LOAD_RGB);
  if(!img){
    cout<<"ERROR::LOAD_IMAGE::"<<file<<endl;
    return;
  }
  glBindTexture(GL_TEXTURE_2D,tex);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,w,h,0,GL_RGB,GL_UNSIGNED_BYTE,img);
  glGenerateMipmap(GL_TEXTURE_2D);
  SOIL_free_image_data(img);
  glBindTexture(GL_TEXTURE_2D,0);
  //bind
  GLfloat v[]={w,h,0,
	       w,0,0,
	       0,0,0,
	       0,h,0}
  GLuint  i[]={0,1,3,1,2,3};
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER,vbo);
  glBufferData(GL_ARRAY_BUFFER,20*sizeof(GLfloat),v,GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,6*sizeof(GLuint),i,GL_STATIC_DRAW);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),(GLvoid*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),(GLvoid*)(3*sizeof(GLfloat)));
  glEnableVertexAttribArray(1);
  glBindVertexArray(0);
}
void csprite::display(){
  glBindTexture(GL_TEXTURE_2D,tex);
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
  glBindVertexArray(0);
}
