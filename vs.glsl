#version 330 core

layout (location=0) in vec3 pos0;
layout (location=1) in vec3 col0;
layout (location=2) in vec2 tex0;
out vec3 col1;
out vec2 tex1;
uniform mat4 transform;
void main(){
  gl_Position=transform*vec4(pos0,1.0f);
  col1=col0;
  tex1=tex0;
}
