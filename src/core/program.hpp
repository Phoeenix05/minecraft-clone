#ifndef __PROGRAM_HPP__
#define __PROGRAM_HPP__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/vec3.hpp>

#include <iostream>
#include <memory>
#include <vector>

#include "window.hpp"
#include "camera.hpp"
#include "graphics/shader.hpp"

class Application
{
private:
  std::unique_ptr<Window> m_window;
  std::unique_ptr<Shader> m_shader;
  std::unique_ptr<Camera> m_camera;

public:
  Application();
  ~Application() = default;

  void run();
};

#endif