#version 330 core

layout(location = 0) in vec3 vertexPos;
layout(location = 1) in vec3 fragmentColor;

uniform mat4 u_view;
uniform mat4 u_projection;

out vec3 color;

void main() {
  gl_Position = u_projection * u_view * vec4(vertexPos, 1.0);
  color = fragmentColor;
}