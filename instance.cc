#include<cmath>
#define GLM_FORCE_RADIANS
#include<glm/glm.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/transform.hpp>
#include"instance.hh"
#include"common.hh"
#include"utils.hh"
using namespace glm;

instance::instance(float x,float y,string sprite):x(x),y(y),sprite(sprite){
  speed=direction=vspeed=hspeed=gravity=friction=0;
  imageindex=imagespeed=0;
  xscale=yscale=1;
  state=NOTDEAD;
  tltime=tlnode=0;
  for(int i=0;i<11;++i) alarm[i]=0;
}
void instance::move(){
  x+=hspeed;
  y+=vspeed;
  x+=speed*cos(degtorad(direction));
  y+=speed*sin(degtorad(direction));
  vspeed-=gravity;
  hspeed-=friction*sign(hspeed);
  vspeed-=friction*sign(vspeed);
  speed-=friction*sign(speed);
}
void instance::setmodel(GLuint program){
  mat4 model,texmodel;
  model=translate(model,vec3(x,y,0.0f));
  model=scale(model,vec3(xscale,yscale,1.0f));
  GLuint modelloc=glGetUniformLocation(program,"model");
  glUniformMatrix4fv(modelloc,1,GL_FALSE,value_ptr(model));
  imageindex+=imagespeed;
}
