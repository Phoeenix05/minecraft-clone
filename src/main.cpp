#include <iostream>

#define GLEW_STATIC
#define GL_SILENCE_DEPRECATION

#include "log.hpp"
#include "core/program.hpp"

int main()
{
  auto l_application = std::make_unique<Application>();
  l_application->run();
}
