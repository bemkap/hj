#include<GL/glew.h>
#include<GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#include<glm/glm.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/transform.hpp>
#include<fstream>
#include"common.hh"
#include"graphicmng.hh"
using namespace std;
using namespace glm;

static GLuint newprogram(GLuint vertexshader,GLuint fragmentshader){
  GLuint prg=glCreateProgram();
  glAttachShader(prg,vertexshader);
  glAttachShader(prg,fragmentshader);
  glLinkProgram(prg);
  return prg;
}
static GLuint newshader(GLenum t,const char*f){
  GLuint shader=glCreateShader(t);
  ifstream stream(f,ios::in);
  string code;
  if(stream.is_open()){
    for(string line="";getline(stream,line);code+="\n"+line);
    stream.close();
  }
  const char*source=code.c_str();
  glShaderSource(shader,1,&source,nullptr);
  glCompileShader(shader);
  GLint success;
  GLchar infoLog[512];
  glGetShaderiv(shader,GL_COMPILE_STATUS,&success);
  if(!success){
    glGetShaderInfoLog(shader,512,NULL,infoLog);
    cout<<"ERROR::SHADER::COMPILATION_FAILED"<<endl<<infoLog<<endl;
  }
  return shader;
}
void cgraphicmng::init(){
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
  if(!(window=glfwCreateWindow(500,500,"OpenGL",nullptr,nullptr))){
    cout<<"ERROR::WINDOW::CREATION_FAILED"<<endl;
    close();
    exit(0);
  }
  glfwMakeContextCurrent(window);
  glewExperimental=GL_TRUE;
  glewInit();
  glfwGetFramebufferSize(window,&winwidth,&winheight);
  xcenter=(GLfloat)winwidth/2;
  ycenter=(GLfloat)winheight/2;
  glViewport(0,0,winwidth,winheight);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
  GLuint vs=newshader(GL_VERTEX_SHADER,"vs.glsl");
  GLuint fs=newshader(GL_FRAGMENT_SHADER,"fs.glsl");
  program=newprogram(vs,fs);
  glDeleteShader(vs);
  glDeleteShader(fs);
}
void cgraphicmng::close(){
  glfwTerminate();
}
void cgraphicmng::clear(){
  glClearColor(0.0,0.0,0.1,1);
  glClear(GL_COLOR_BUFFER_BIT);
}
void cgraphicmng::reshape(GLsizei w,GLsizei h){
  glfwSetWindowSize(window,w,h);
  glViewport(0,0,w,h);
  winwidth=w;
  winheight=h;
}
void cgraphicmng::setcamera(){
  glUseProgram(program);
  mat4 projection;
  GLfloat wo2=(GLfloat)winwidth/2;
  GLfloat ho2=(GLfloat)winheight/2;
  projection=ortho(xcenter-wo2,xcenter+wo2,ycenter-ho2,ycenter+ho2);
  GLuint projectionloc=glGetUniformLocation(program,"projection");
  glUniformMatrix4fv(projectionloc,1,GL_FALSE,value_ptr(projection));
}
void cgraphicmng::flip(){
  glfwSwapBuffers(window);
}
