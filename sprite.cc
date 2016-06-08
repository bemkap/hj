#include<iostream>
#include<GL/glew.h>
#include<SOIL/SOIL.h>
#define GLM_FORCE_RADIANS
#include<glm/glm.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/transform.hpp>
#include"sprite.hh"
#include<stdio.h>
using namespace glm;

csprite::csprite(string file):current(0){
  //gen buffers
  glGenBuffers(1,&vertexvbo);
  glGenBuffers(1,&texturevbo);
  glGenVertexArrays(1,&vao);
  glGenBuffers(1,&ebo);
  glGenTextures(1,&tex);
  //parse filename
  int n=file.find_last_of("/\\");
  int m=file.find_last_of(".");
  char temp[128];
  sscanf(file.substr(n+1,m).c_str(),"%s %d %d %d",temp,&fwidth,&fheight,&frames);
  name=temp;
  //create texture
  int w,h;
  unsigned char*img=SOIL_load_image(file.c_str(),&w,&h,0,SOIL_LOAD_RGB);
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
  GLuint v[]={fwidth,fheight,0,
	      fwidth,      0,0,
	           0,      0,0,
	           0,fheight,0};
  GLuint i[]={0,1,3,1,2,3};
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER,vertexvbo);
  glBufferData(GL_ARRAY_BUFFER,12*sizeof(GLuint),v,GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,6*sizeof(GLuint),i,GL_STATIC_DRAW);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),(GLvoid*)0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER,texturevbo);
  glBufferData(GL_ARRAY_BUFFER,8*frames*sizeof(GLuint),v,GL_STATIC_DRAW);
  glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),(GLvoid*)0);
  glEnableVertexAttribArray(1);
  glBindVertexArray(0);
}
void csprite::display(GLuint program){
  mat4 texmodel;
  texmodel=translate(texmodel,vec3(current*fwidth,0.0f,0.0f));
  GLuint texmodelloc=glGetUniformLocation(program,"texmodel");
  glUniformMatrix4fv(texmodelloc,1,GL_FALSE,value_ptr(texmodel));
  glBindTexture(GL_TEXTURE_2D,tex);
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
  glBindVertexArray(0);
  current=(current+1)%frames;
}
