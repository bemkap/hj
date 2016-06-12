#include"main.hh"
#include<stdio.h>

int main(int argc,char**argv){
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
