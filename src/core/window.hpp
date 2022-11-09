#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdint>
#include <string>

#include "log.hpp"

class Window
{
private:
  GLFWwindow *m_window;

public:
  Window(uint32_t w, uint32_t h, std::string title);
  ~Window() = default;

  inline constexpr GLFWwindow *getWindow() const { return m_window; }

  void clear();
  void update();

  double deltaTime();
};

#endif