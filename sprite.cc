#include<iostream>
#include<SOIL/SOIL.h>
#define GLM_FORCE_RADIANS
#include<glm/glm.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/transform.hpp>
#include"sprite.hh"
#include<stdio.h>
using namespace glm;

csprite::csprite(const string&file){
  //gen buffers
  glGenBuffers(1,&vertexvbo);
  glGenBuffers(1,&texturevbo);
  glGenVertexArrays(1,&vao);
  glGenBuffers(1,&ebo);
  glGenTextures(1,&tex);
  //parse filename
  int n=file.find_last_of("/\\")+1;
  int m=file.find_last_of(".");
  char temp[128];
  GLfloat fw,fh;
  sscanf(file.substr(n,m-n).c_str(),"%s %f %f %u",temp,&fw,&fh,&frames);
  name=temp;
  //create texture
  int w,h;
  unsigned char*img=SOIL_load_image(file.c_str(),&w,&h,0,SOIL_LOAD_RGBA);
  if(!img){
    cout<<"ERROR::LOAD_IMAGE::"<<file<<"::"<<SOIL_last_result()<<endl;
    return;
  }
  fwidth=fw/w;fheight=fh/h;
  glBindTexture(GL_TEXTURE_2D,tex);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,w,h,0,GL_RGBA,GL_UNSIGNED_BYTE,img);
  glGenerateMipmap(GL_TEXTURE_2D);
  SOIL_free_image_data(img);
  glBindTexture(GL_TEXTURE_2D,0);
  //bind
  GLfloat v[]={fw,fh,0,fw,0,0,0,0,0,0,fh,0};
  GLfloat t[]={fwidth,fheight,fwidth,0,0,0,0,fheight};
  GLuint i[]={0,1,3,1,2,3};
  glBindVertexArray(vao);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,6*sizeof(GLfloat),i,GL_STATIC_DRAW); 
  glBindBuffer(GL_ARRAY_BUFFER,vertexvbo);
  glBufferData(GL_ARRAY_BUFFER,12*sizeof(GLfloat),v,GL_STATIC_DRAW);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLuint),(GLvoid*)0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER,texturevbo);
  glBufferData(GL_ARRAY_BUFFER,8*sizeof(GLfloat),t,GL_STATIC_DRAW);
  glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,2*sizeof(GLfloat),(GLvoid*)0);
  glEnableVertexAttribArray(1);
  glBindVertexArray(0);
}
void csprite::display(GLuint program,float&imageindex){
  mat4 texmodel;
  if(imageindex>frames) imageindex-=frames;
  texmodel=translate(texmodel,vec3((GLuint)imageindex*fwidth,0.0f,0.0f));
  GLuint texmodelloc=glGetUniformLocation(program,"texmodel");
  glUniformMatrix4fv(texmodelloc,1,GL_FALSE,value_ptr(texmodel));
  glBindTexture(GL_TEXTURE_2D,tex);
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
  glBindVertexArray(0);
}
void csprite::display(GLuint program,float x,float y){
  mat4 model,texmodel;
  model=translate(model,vec3(x,y,0.0f));
  GLuint modelloc=glGetUniformLocation(program,"model");
  glUniformMatrix4fv(modelloc,1,GL_FALSE,value_ptr(model));
  GLuint texmodelloc=glGetUniformLocation(program,"texmodel");
  glUniformMatrix4fv(texmodelloc,1,GL_FALSE,value_ptr(texmodel));
  glBindTexture(GL_TEXTURE_2D,tex);
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
  glBindVertexArray(0);
}
