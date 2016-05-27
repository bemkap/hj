#include<GL/glew.h>
#include<GLFW/glfw3.h>
//#include<GL/glu.h>
//#include<GL/glut.h>
#include"common.hh"
#include"graphicmng.hh"

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
  while(!glfwWindowShouldClose(w)){
    glfwPollEvents();
    glfwSwapBuffers(w);
  }
  //glutInit(0,NULL);
  //glutInitDisplayMode(GLUT_DOUBLE);
  //glutInitWindowSize(240,480);
  //glutCreateWindow("OpenGL");
  //glutReshapeFunc(cgraphicmng::reshape);
}
void cgraphicmng::close(){
  glfwTerminate();
}
void cgraphicmng::clear(){
  glClearColor(0,0,0,1);
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
