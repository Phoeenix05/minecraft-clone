#include "mesh.hpp"

Mesh::Mesh(Vertex vertices[])
{
  glGenVertexArrays(1, &m_vao);
  glBindVertexArray(m_vao);

  std::vector<GLfloat> l_vertices;
  for (int i = 0; i < sizeof(vertices); i++)
  {
    l_vertices.push_back(vertices[i].m_pos.x);
    l_vertices.push_back(vertices[i].m_pos.y);
    l_vertices.push_back(vertices[i].m_pos.z);
  }
  
  glGenBuffers(1, &m_vbo);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(l_vertices), &l_vertices[0], GL_STATIC_DRAW);
  
  std::vector<GLfloat> l_color;
  for (int i = 0; i < sizeof(vertices); i++)
  {
    l_color.push_back(vertices[i].m_color.x);
    l_color.push_back(vertices[i].m_color.y);
    l_color.push_back(vertices[i].m_color.z);
  }
  
  glGenBuffers(1, &m_cbo);
  glBindBuffer(GL_ARRAY_BUFFER, m_cbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(l_color), &l_color[0], GL_STATIC_DRAW);
}