#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <GL/glew.h>

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>

#include "graphics/shader.hpp"

class Camera
{
private:
  glm::mat4 m_view;
  glm::mat4 m_projection;

public:
  Camera(glm::vec3 const pos, glm::vec3 const poi, float const fov, float const aspectr, float const near, float const far);
  ~Camera() = default;

  void update(GLuint viewLocation, GLuint projectionLocation);
};

#endif