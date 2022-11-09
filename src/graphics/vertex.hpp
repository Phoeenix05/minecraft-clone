#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

// #include <glm/vec2.hpp>
#include <glm/vec3.hpp>
// #include <glm/vec4.hpp>

class Vertex
{
public:
  const glm::vec3 m_pos;
  const glm::vec3 m_color;

  inline Vertex(glm::vec3 pos, glm::vec3 color) : m_pos(pos), m_color(color) {}
  ~Vertex();
};

#endif