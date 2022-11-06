#ifndef __PROGRAM_HPP__
#define __PROGRAM_HPP__

#include <memory>

#include "window.hpp"

class Application {
private:
  std::unique_ptr<Window> m_window;

public:
  Application();
  ~Application() = default;

  void run();
};

#endif