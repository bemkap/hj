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
  GLint success;
  GLchar infoLog[512];
  glGetShaderiv(shader,GL_COMPILE_STATUS,&success);
  if(!success){
    glGetShaderInfoLog(shader,512,NULL,infoLog);
    cout<<"ERROR::SHADER::VERTEX::COMPILATION_FAILED"<<endl<<infoLog<<endl;
  }
  return shader;
}
void cgraphicmng::init(){
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
  w=glfwCreateWindow(800,600,"OpenGL",nullptr,nullptr);
  glfwMakeContextCurrent(w);
  glewExperimental=GL_TRUE;
  glewInit();
  int width,height;
  glfwGetFramebufferSize(w,&width,&height);
  glViewport(0,0,width,height);
  GLuint vs=newshader(GL_VERTEX_SHADER,"shader/vs.glsl");
  GLuint fs=newshader(GL_FRAGMENT_SHADER,"shader/fs.glsl");
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
}
void cgraphicmng::display(string n,double x,double y,double xsc,double ysc){
  csprite*s=sprites.get(n);
  if(s) s->display(program,x,y,xsc,ysc);
}
void cgraphicmng::flip(){
  glfwSwapBuffers(w);
}
