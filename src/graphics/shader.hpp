#ifndef __SHADER_HPP__
#define __SHADER_HPP__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <vector>

#include "log.hpp"

class Shader
{
private:
  GLuint m_programID;

public:
  Shader();
  ~Shader() = default;

  inline constexpr GLuint getProgram() const { return m_programID; }
};

#endif