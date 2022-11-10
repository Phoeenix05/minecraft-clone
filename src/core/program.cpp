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

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  while (!glfwWindowShouldClose(m_window->getWindow()))
  {
    // auto l_deltaTime = m_window->deltaTime();

    m_window->clear();                    // Clear window (GLFW)
    glUseProgram(m_shader->getProgram()); // Enable shader program
    m_camera->update(l_viewLocation, l_projectionLocation);

    glUseProgram(0);    // Disable shader program
    m_window->update(); // Update window (GLFW)
  }

  glfwDestroyWindow(m_window->getWindow()); // Destroy GLFW window
  glfwTerminate();                          // Terminate GLFW
}
