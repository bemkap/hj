#include<iostream>
#include<GL/glew.h>
#include<SOIL/SOIL.h>
#include<glm/glm.hpp>
#include"sprite.hh"
using namespace glm;

csprite::csprite(const char*file,lua_State*L){
  glGenBuffers(1,&vbo);
  glGenVertexArrays(1,&vao);
  glGenBuffers(1,&ebo);
  if(0<luaL_dofile(L,file)){
    cout<<"ERROR::LOAD_SCRIPT::"<<file<<endl;
  }else{
    GLfloat v[4*5]={32,32,0,0,0,32,0,0,0,0,0,0,0,0,0,0,32,0,0,0};
    if(lua_istable(L,-1)){
      lua_pushnil(L);
      while(lua_next(L,-2)!=0){
	string a=lua_tostring(L,-2);
	if(a=="name") name=lua_tostring(L,-1);
	else if(a=="texture") texture(lua_tostring(L,-1));
	else if(a=="tilex") v[3]=v[8]=1+(v[13]=v[18]=lua_tonumber(L,-1));
	else if(a=="tiley") v[4]=v[19]=1+(v[14]=v[9]=lua_tonumber(L,-1));
	lua_pop(L,1);
      }
      bind(v);
    }
  }
}
void csprite::bind(GLfloat*v){
  GLuint i[]={0,1,3,1,2,3};
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
void csprite::texture(string file){
  int width,height;
  unsigned char*img=SOIL_load_image(file.c_str(),&width,&height,0,SOIL_LOAD_RGB);
  if(!img){
    cout<<"ERROR::LOAD_IMAGE::"<<file<<endl;
    return;
  }
  glGenTextures(1,&tex);
  glBindTexture(GL_TEXTURE_2D,tex);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,img);
  glGenerateMipmap(GL_TEXTURE_2D);
  SOIL_free_image_data(img);
  glBindTexture(GL_TEXTURE_2D,0);
}
void csprite::display(double x,double y,double xsc,double ysc){
  glBindTexture(GL_TEXTURE_2D,tex);
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
  glBindVertexArray(0);
}
