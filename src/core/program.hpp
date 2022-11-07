#ifndef __PROGRAM_HPP__
#define __PROGRAM_HPP__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <memory>

#include "window.hpp"
#include "graphics/shader.hpp"

class Application
{
private:
  std::unique_ptr<Window> m_window;
  std::unique_ptr<Shader> m_shader;

public:
  Application();
  ~Application() = default;

  void run();
};

#endif