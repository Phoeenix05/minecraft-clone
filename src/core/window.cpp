#include "window.hpp"

Window::Window(uint32_t w, uint32_t h, std::string title)
{
  if (!glfwInit())
    throw LOG_ERROR("Unable to initialize GLFW");

#ifdef __APPLE__
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
  glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  m_window = glfwCreateWindow(w, h, title.c_str(), nullptr, nullptr);
  if (m_window == NULL)
  {
    glfwTerminate();
    throw LOG_ERROR("Failed to create GLFW window");
  }

  glfwMakeContextCurrent(m_window);
  glfwSwapInterval(1);
  glfwShowWindow(m_window);

  if (int err = glewInit(); err != GLEW_OK)
  {
    glfwTerminate();
    throw LOG_ERROR(glewGetErrorString(err));
  }
}

void Window::clear()
{
  glClearColor(0.1f, 0.1f, 0.1f, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update()
{
  glfwSwapBuffers(m_window);
  glfwPollEvents();
}