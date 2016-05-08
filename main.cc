#include"main.hh"

static en&env=eget();

int main(int argc,char**argv){
  init(&argc,argv);
  loadsps();loadobs();loadtls();loadros();
  env.swro("ro0");
  env.obs.get("enem")->tline=env.tls.get("tl0");
  instance_create(env,"worl",0,0);
  in*ship0=instance_create(env,"ship",20,20);
  ship0->xsc=ship0->ysc=2;
  instance_create(env,"enem",50,300);
  glutMainLoop();
  return 0;
}
