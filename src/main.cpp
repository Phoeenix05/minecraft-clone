#include <iostream>

#define GLEW_STATIC
#define GL_SILENCE_DEPRECATION
#define STB_IMAGE_IMPLEMENTATION

#include "log.hpp"
#include "core/program.hpp"

int main()
{
  auto l_application = std::make_unique<Application>();
  l_application->run();
}
