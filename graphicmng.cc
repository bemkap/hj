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
  if(!(w=glfwCreateWindow(500,500,"OpenGL",nullptr,nullptr))){
    cout<<"ERROR::WINDOW::CREATION_FAILED"<<endl;
    close();
    exit(0);
  }
  glfwMakeContextCurrent(w);
  glewExperimental=GL_TRUE;
  glewInit();
  int width,height;
  glfwGetFramebufferSize(w,&width,&height);
  glViewport(0,0,width,height);
  GLuint vs=newshader(GL_VERTEX_SHADER,"vs.glsl");
  GLuint fs=newshader(GL_FRAGMENT_SHADER,"fs.glsl");
  program=newprogram(vs,fs);
  glDeleteShader(vs);
  glDeleteShader(fs);
  camera.x=-3;
  camera.y=-3;
  camera.z=-3;
}
void cgraphicmng::close(){
  glfwTerminate();
}
void cgraphicmng::clear(){
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
}
void cgraphicmng::reshape(GLsizei w,GLsizei h){
}
void cgraphicmng::display(string n,double x,double y){
  csprite*s=sprites.get(n);
  if(s){
    glUseProgram(program);
    mat4 model;
    model=translate(model,vec3(x,y,0.0f));
    mat4 view;
    view=lookAt(camera,camera+vec3(3,3,3),vec3(0.0f,0.0f,1.0f));
    mat4 projection;
    projection=ortho(-250.0f,250.0f,-250.0f,250.0f,-355.0f,355.0f);
    mat4 texmodel;
    texmodel=translate(texmodel,vec3(s->fwidth*s->fcurrent,0.0f,0.0f));
    GLuint modelloc=glGetUniformLocation(program,"model");
    GLuint viewloc=glGetUniformLocation(program,"view");
    GLuint projectionloc=glGetUniformLocation(program,"projection");
    GLuint texmodelloc=glGetUniformLocation(program,"texmodel");
    glUniformMatrix4fv(modelloc,1,GL_FALSE,value_ptr(model));
    glUniformMatrix4fv(viewloc,1,GL_FALSE,value_ptr(view));
    glUniformMatrix4fv(projectionloc,1,GL_FALSE,value_ptr(projection));
    glUniformMatrix4fv(texmodelloc,1,GL_FALSE,value_ptr(texmodel));
    s->display();
  }
}
void cgraphicmng::flip(){
  glfwSwapBuffers(w);
}
