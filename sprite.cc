#include<iostream>
#include<GL/glew.h>
#include<SOIL/SOIL.h>
#include<glm/glm.hpp>
#define GLM_FORCE_RADIANS
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"sprite.hh"

csprite::csprite():size(0){
  glGenBuffers(1,&vbo);
  glGenVertexArrays(1,&vao);
  glGenBuffers(1,&ebo);
}
void csprite::bind(GLuint*i,GLsizeiptr si,GLfloat*v,GLsizeiptr sv){
  size=si;
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER,vbo);
  glBufferData(GL_ARRAY_BUFFER,sv*sizeof(GLfloat),v,GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,si*sizeof(GLuint),i,GL_STATIC_DRAW);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(GLfloat),(GLvoid*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(GLfloat),(GLvoid*)(3*sizeof(GLfloat)));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(GLfloat),(GLvoid*)(6*sizeof(GLfloat)));
  glEnableVertexAttribArray(2);
  glBindVertexArray(0);
}
void csprite::texture(string f){
  int width,height;
  unsigned char*img=SOIL_load_image(f.c_str(),&width,&height,0,SOIL_LOAD_RGB);
  if(!img){
    cout<<"failed to load image"<<f<<endl;
    return;
  }
  glGenTextures(1,&tex);
  glBindTexture(GL_TEXTURE_2D,tex);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,img);
  glGenerateMipmap(GL_TEXTURE_2D);
  SOIL_free_image_data(img);
  glBindTexture(GL_TEXTURE_2D,0);
}
void csprite::display(GLuint prg,double x,double y,double xsc,double ysc){
  glUseProgram(prg);
  GLuint transform=glGetUniformLocation(prg,"transform");
  glm::mat4 matrix;
  matrix=glm::scale(matrix,glm::vec3(xsc,ysc,1.0f));
  matrix=glm::translate(matrix,glm::vec3(x,y,0.0f));
  glUniformMatrix4fv(transform,1,GL_FALSE,glm::value_ptr(matrix));
  glBindTexture(GL_TEXTURE_2D,tex);
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES,size,GL_UNSIGNED_INT,0);
  glBindVertexArray(0);
}
