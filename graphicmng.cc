#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<fstream>
#include"common.hh"
#include"graphicmng.hh"
using namespace std;

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
  return shader;
}
void loadspr(){}
void cgraphicmng::init(){
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
  w=glfwCreateWindow(240,480,"OpenGL",nullptr,nullptr);
  if(!w){cout<<"window failed"<<endl;close();}
  glfwMakeContextCurrent(w);
  glewExperimental=GL_TRUE;
  if(glewInit()!=GLEW_OK){cout<<"init failed"<<endl;close();}
  int width,height;
  glfwGetFramebufferSize(w,&width,&height);
  glViewport(0,0,width,height);
  GLuint vs=newshader(GL_VERTEX_SHADER,"vs.glsl");
  GLuint fs=newshader(GL_FRAGMENT_SHADER,"fs.glsl");
  GLuint prg=newprogram(vs,fs);
  glUseProgram(prg);
  glDeleteShader(vs);
  glDeleteShader(fs);
  while(!glfwWindowShouldClose(w)){
    glfwPollEvents();
    clear();
    glfwSwapBuffers(w);
  }  
}
void cgraphicmng::close(){
  glfwTerminate();
}
void cgraphicmng::clear(){
  glClearColor(0.1,0.2,0.6,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
}
void cgraphicmng::reshape(GLsizei w,GLsizei h){
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,w,0,h);
  glMatrixMode(GL_MODELVIEW);
}
void cgraphicmng::display(string n,double x,double y,double xsc,double ysc){
  csprite*s=sprites.get(n);
  if(s) s->display(x,y,xsc,ysc);
}
void cgraphicmng::flip(){
  glfwSwapBuffers(w);
}
