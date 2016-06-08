#include"main.hh"

int main(int argc,char**argv){
  env&env=env::envget();
  env.init();
  while(!glfwWindowShouldClose(env.graphicmng.w)){
    glfwPollEvents();    
    env.update();
    env.display();
  }
  env.close();
  return 0;
}
