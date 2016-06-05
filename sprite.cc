#include<iostream>
#include<GL/glew.h>
#include<SOIL/SOIL.h>
#include<glm/glm.hpp>
#define GLM_FORCE_RADIANS
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"sprite.hh"
using namespace glm;

csprite::csprite():size(0){
  glGenBuffers(1,&vbo);
  glGenVertexArrays(1,&vao);
  glGenBuffers(1,&ebo);
<<<<<<< HEAD
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
=======
>>>>>>> parent of d7b0130... isometric? generico o ..?
}
void csprite::bind(GLuint*i,GLsizeiptr si,GLfloat*v,GLsizeiptr sv){
  size=si;
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER,vbo);
  glBufferData(GL_ARRAY_BUFFER,sv*sizeof(GLfloat),v,GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,si*sizeof(GLuint),i,GL_STATIC_DRAW);
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
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,img);
  glGenerateMipmap(GL_TEXTURE_2D);
  SOIL_free_image_data(img);
  glBindTexture(GL_TEXTURE_2D,0);
}
void csprite::display(GLuint prg,double x,double y,double xsc,double ysc){
  glUseProgram(prg);
  mat4 model;
  model=rotate(model,radians(-60.0f),vec3(1.0f,0.0f,0.0f));
  model=rotate(model,radians(-30.0f),vec3(0.0f,0.0f,1.0f));
  model=scale(model,vec3(xsc,ysc,1.0f));
  model=translate(model,vec3(x,y,0.0f));
  mat4 view;
  view=translate(view,vec3(0.0f,0.0f,-3.0f));
  mat4 projection;
  //projection=ortho(-0.0f,400.0f,-300.0f,300.0f,0.1f,100.0f);
  projection=perspective(radians(45.0f),4.0f/3.0f,0.1f,100.0f);
  GLuint modelloc=glGetUniformLocation(prg,"model");
  GLuint viewloc=glGetUniformLocation(prg,"view");
  GLuint projectionloc=glGetUniformLocation(prg,"projection");
  glUniformMatrix4fv(modelloc,1,GL_FALSE,value_ptr(model));
  glUniformMatrix4fv(viewloc,1,GL_FALSE,value_ptr(view));
  glUniformMatrix4fv(projectionloc,1,GL_FALSE,value_ptr(projection));
  glBindTexture(GL_TEXTURE_2D,tex);
  glBindVertexArray(vao);
  glDrawElements(GL_TRIANGLES,size,GL_UNSIGNED_INT,0);
  glBindVertexArray(0);
}
