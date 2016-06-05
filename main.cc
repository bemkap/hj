#include"main.hh"

int main(int argc,char**argv){
  env&env=envget();
  env.init();
  env.instancecreate("ship",0,0);
  while(!glfwWindowShouldClose(env.graphicmng.w)){
    glfwPollEvents();    
    env.update();
    env.display();
  }
  env.close();
  return 0;
}
