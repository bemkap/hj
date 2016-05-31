#version 330 core

in vec3 vcolor;
in vec2 vtex;
out vec4 color;
uniform sampler2D ftexture0;
void main(){
  color=texture(ftexture0,vtex)*vec4(vcolor,1.0f);
}
