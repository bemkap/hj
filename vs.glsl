#version 330 core

layout (location=0) in vec3 pos0;
layout (location=1) in vec2 tex0;
out vec2 tex1;
uniform mat4 model;
uniform mat4 projection;
uniform mat4 texmodel;
void main(){
  gl_Position=projection*model*vec4(pos0,1.0f);
  vec4 v=texmodel*vec4(tex0,0.0f,1.0f);
  tex1=v.xy;
}
