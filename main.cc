#include"main.hh"

static env&env=envget();

int main(int argc,char**argv){
  env.init();
  env.close();
  //init(&argc,argv);
  //glutMainLoop();
  return 0;
}
