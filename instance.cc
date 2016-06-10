#include<cmath>
#include"instance.hh"
#include"common.hh"
#include"utils.hh"

instance::instance(float x,float y,csprite*sprite):x(x),y(y),sprite(sprite){
  speed=direction=vspeed=hspeed=gravity=friction=0;
  current=imagespeed=0;
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
void instance::display(GLuint program){
  mat4 model;
  model=scale(model,vec3(xscale,yscale,1.0f));
  model=translate(model,vec3(x,y,0.0f));
  GLuint modelloc=glGetUniformLocation(program,"model");
  glUniformMatrix4fv(modelloc,1,GL_FALSE,value_ptr(model));
  GLfloat t=(GLuint)current*sprite->fwidth;
  texmodel=translate(texmodel,vec3(t,0.0f,0.0f));
  GLuint texmodelloc=glGetUniformLocation(program,"texmodel");
  glUniformMatrix4fv(texmodelloc,1,GL_FALSE,value_ptr(texmodel));
  sprite->display(program);
  current+=imagespeed;
  if(current>=sprite->frames) current-=sprite->frames;
}
