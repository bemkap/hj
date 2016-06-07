#version 330 core

in vec2 tex1;
out vec4 color;
uniform sampler2D tex2;
void main(){
  color=texture(tex2,tex1);
}
