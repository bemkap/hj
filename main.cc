#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"env.hh"

int main(){
  env&env=env::envget();
  env.init();
  env.switchroom("room0");
  while(!glfwWindowShouldClose(env.graphicmng.window)){
    glfwPollEvents();    
    env.update();
    env.display();
  }
  env.close();
  return 0;
}
