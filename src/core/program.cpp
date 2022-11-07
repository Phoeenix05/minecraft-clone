#include "program.hpp"

Application::Application()
{
  m_window = std::make_unique<Window>(1280, 720, "Minecraft Clone");
  m_shader = std::make_unique<Shader>();
}

void Application::run()
{
  while (!glfwWindowShouldClose(m_window->getWindow()))
  {
    m_window->clear();                    // Clear window (GLFW)
    glUseProgram(m_shader->getProgram()); // Enable shader program

    // Rendering code 

    glUseProgram(0);    // Disable shader program
    m_window->update(); // Update window (GLFW)
  }

  glfwDestroyWindow(m_window->getWindow()); // Destroy GLFW window
  glfwTerminate();                          // Terminate GLFW
}
