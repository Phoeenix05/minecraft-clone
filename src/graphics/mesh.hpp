#ifndef __MEHS_HPP__
#define __MEHS_HPP__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "vertex.hpp"

class Mesh
{
private:
  GLuint m_vao, m_vbo, m_cbo, m_ibo;

public:
  Mesh(Vertex vertices[]);
  ~Mesh();
};

#endif