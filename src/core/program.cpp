#include "program.hpp"

Application::Application() {
  m_window = std::make_unique<Window>(1280, 720, "Minecraft Clone");
}

void Application::run() {
  while (!glfwWindowShouldClose(m_window->getWindow())) {
    m_window->clear();

    m_window->update();
  }

  glfwDestroyWindow(m_window->getWindow());
  glfwTerminate();
}
