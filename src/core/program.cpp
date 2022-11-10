#include "program.hpp"

Application::Application()
{
  m_window = std::make_unique<Window>(1280, 720, "Minecraft Clone");
  m_shader = std::make_unique<Shader>();
  m_camera = std::make_unique<Camera>(glm::vec3(0, 0, 8), glm::vec3(0, 0, 0), 70.0f, 1280.0f / 720.0f, 0.1f, 100.0f);
}

void Application::run()
{
  auto l_viewLocation = glGetUniformLocation(m_shader->getProgram(), "u_view");
  auto l_projectionLocation = glGetUniformLocation(m_shader->getProgram(), "u_projection");

  GLuint l_vao;
  glGenVertexArrays(1, &l_vao);
  glBindVertexArray(l_vao);

  const GLfloat l_vertices[] = {
      0, 3, 0,
      -3, -3, 0,
      3, -3, 0};
  GLuint l_vbo;
  glGenBuffers(1, &l_vbo);
  glBindBuffer(GL_ARRAY_BUFFER, l_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(l_vertices), l_vertices, GL_STATIC_DRAW);

  const GLfloat l_color[] = {
      0, 0, 1,
      1, 0, 0,
      1, 0, 1};
  GLuint l_cbo;
  glGenBuffers(1, &l_cbo);
  glBindBuffer(GL_ARRAY_BUFFER, l_cbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(l_color), l_color, GL_STATIC_DRAW);

  const GLuint l_indices[] = {0, 1, 2};
  GLuint l_ibo;
  glGenBuffers(1, &l_ibo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, l_ibo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(l_indices), l_indices, GL_STATIC_DRAW);

  while (!glfwWindowShouldClose(m_window->getWindow()))
  {
    // auto l_deltaTime = m_window->deltaTime();

    m_window->clear();                    // Clear window (GLFW)
    glUseProgram(m_shader->getProgram()); // Enable shader program
    m_camera->update(l_viewLocation, l_projectionLocation);

    glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, l_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glBindBuffer(GL_ARRAY_BUFFER, l_cbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glDrawElements(GL_TRIANGLES, sizeof(l_indices), GL_UNSIGNED_INT, nullptr);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    glUseProgram(0);    // Disable shader program
    m_window->update(); // Update window (GLFW)
  }

  glfwDestroyWindow(m_window->getWindow()); // Destroy GLFW window
  glfwTerminate();                          // Terminate GLFW
}
