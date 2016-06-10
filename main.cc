#include"main.hh"

int main(int argc,char**argv){
  env&env=env::envget();
  env.init();
  env.instancecreate("warrior",0.0f,0.0f);
  env.switchroom("room0");
  while(!glfwWindowShouldClose(env.graphicmng.window)){
    glfwPollEvents();    
    env.update();
    env.display();
  }
  env.close();
  return 0;
}
