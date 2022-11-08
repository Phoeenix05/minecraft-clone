#version 330 core

layout(location = 0) in vec3 vertexPos;

uniform mat4 u_view;
uniform mat4 u_projection;

void main() {
  gl_Position = u_projection * u_view * vec4(vertexPos, 1.0);
}