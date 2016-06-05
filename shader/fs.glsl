#version 330 core

in vec2 tex1;
out vec4 color;
uniform sampler2D tex2;
void main(){
  vec2 mult=tex1/64;
  color=texture(tex2,mult);
}
