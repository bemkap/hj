#include"main.hh"

static en&env=eget();

int main(int argc,char**argv){
  init(&argc,argv);
  env.init();
  glutMainLoop();
  return 0;
}
