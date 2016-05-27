#include"main.hh"

static env&env=envget();

int main(int argc,char**argv){
  env.init();
  GLfloat v[]={
    -0.5f,-0.5f,0.0f,
     0.5f,-0.5f,0.0f,
     0.0f, 0.5f,0.0f};
  csprite s;s.vertices=v;
  glBindBuffer(GL_ARRAY_BUFFER,s.vbo);
  glBufferData(GL_ARRAY_BUFFER,sizeof(v),v,GL_STATIC_DRAW);
  env.close();
  //init(&argc,argv);
  //glutMainLoop();
  return 0;
}
