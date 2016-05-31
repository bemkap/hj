#version 330 core

in vec3 col1;
in vec2 tex1;
out vec4 color;
uniform sampler2D tex2;
void main(){
  color=texture(tex2,tex1)*vec4(col1,1.0f);
}
