#ifndef __PROGRAM_HPP__
#define __PROGRAM_HPP__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <iostream>
#include <memory>
#include <vector>

#include "window.hpp"
#include "graphics/vertex.hpp"
#include "graphics/mesh.hpp"
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