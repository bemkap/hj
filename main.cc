#include"main.hh"

static env&env=envget();

int main(int argc,char**argv){
  init(&argc,argv);
  env.init();
  instance*ship=env.instancecreate("ship",20,20);
  if(ship) cout<<ship->x<<endl;
  glutMainLoop();
  return 0;
}
