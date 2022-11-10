#include "camera.hpp"

Camera::Camera(glm::vec3 const pos, glm::vec3 const poi, float const fov, float const aspectr, float const near, float const far)
{
  // position - Camera's position (XYZ)
  // direction - Point of interest: camera looks at this point
  // right axis - base axis (XYZ)
  m_view = glm::lookAt(pos, poi, glm::vec3(0, 1, 0));

  // fov - Field of view
  // aspect - Camera's aspect ratio
  // near - Rendering start distance
  // far - Rendering stop distance
  m_projection = glm::perspective(glm::radians(fov), aspectr, near, far);
}

void Camera::update(GLuint viewLocation, GLuint projectionLocation)
{
  glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &m_view[0][0]);
  glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &m_projection[0][0]);
}