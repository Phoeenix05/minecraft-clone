#include "program.hpp"

Application::Application()
{
  m_window = std::make_unique<Window>(1280, 720, "Minecraft Clone");
  m_shader = std::make_unique<Shader>();
}

void Application::run()
{
  glm::mat4 view = glm::lookAt(
      glm::vec3(0, 0, 8), // position - Camera's position (XYZ)
      glm::vec3(0, 0, 0), // direction - Point of interest: camera looks at this point
      glm::vec3(0, 1, 0)  // right axis - base axis (XYZ)
  );
  glm::mat4 projection = glm::perspective(
      glm::radians(70.0f), // fov - Field of view
      1280.0f / 720.0f,    // aspect - Camera's aspect ratio
      0.1f,                // near - Rendering start distance
      100.0f               // far - Rendering stop distance
  );

  auto l_viewLocation = glGetUniformLocation(m_shader->getProgram(), "u_view");
  auto l_projectionLocation = glGetUniformLocation(m_shader->getProgram(), "u_projection");

  while (!glfwWindowShouldClose(m_window->getWindow()))
  {
    m_window->clear();                    // Clear window (GLFW)
    glUseProgram(m_shader->getProgram()); // Enable shader program

    glUniformMatrix4fv(l_viewLocation, 1, GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(l_projectionLocation, 1, GL_FALSE, &projection[0][0]);

    glUseProgram(0);    // Disable shader program
    m_window->update(); // Update window (GLFW)
  }

  glfwDestroyWindow(m_window->getWindow()); // Destroy GLFW window
  glfwTerminate();                          // Terminate GLFW
}
