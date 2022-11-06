#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "log.hpp"
#include "core/program.hpp"

int main() {
  auto l_application = std::make_unique<Application>();
  l_application->run();
}
