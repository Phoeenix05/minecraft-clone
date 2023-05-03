#include "program.hpp"

Application::Application()
{
  m_window = std::make_unique<Window>(1280, 720, "Minecraft Clone");
  m_shader = std::make_unique<Shader>();
  m_camera = std::make_unique<Camera>(glm::vec3(0, 0, -8), glm::vec3(0, 0, 0), 70.0f, 1280.0f / 720.0f, 0.1f, 100.0f);
}

void Application::run()
{
  auto l_viewLocation = glGetUniformLocation(m_shader->getProgram(), "u_view");
  auto l_projectionLocation = glGetUniformLocation(m_shader->getProgram(), "u_projection");

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  const GLfloat vertices[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f, 1.0f, 0.0f
  };

  const GLuint indices[] = {
    0, 1, 2
  };

  GLuint vao, vbo, ibo;
  glGenBuffers(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  
  glGenBuffers(1, &ibo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  while (!glfwWindowShouldClose(m_window->getWindow()))
  {
    // auto l_deltaTime = m_window->deltaTime();

    m_window->clear();                    // Clear window (GLFW)
    glUseProgram(m_shader->getProgram()); // Enable shader program
    m_camera->update(l_viewLocation, l_projectionLocation);

    // Rendering code
    glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, nullptr);
    glDisableVertexAttribArray(0);

    glUseProgram(0);    // Disable shader program
    m_window->update(); // Update window (GLFW)
  }

  glfwDestroyWindow(m_window->getWindow()); // Destroy GLFW window
  glfwTerminate();                          // Terminate GLFW
}
