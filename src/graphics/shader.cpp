#include "shader.hpp"

void compileShader(const std::string code, GLuint id) {
  const char *l_shaderSourcePtr = code.c_str();
  glShaderSource(id, 1, &l_shaderSourcePtr, NULL);
  glCompileShader(id);

  GLint l_result = GL_FALSE;
  int l_infoLogLength;

  glGetShaderiv(id, GL_COMPILE_STATUS, &l_result);
  glGetShaderiv(id, GL_INFO_LOG_LENGTH, &l_infoLogLength);
  if (l_infoLogLength > 0) {
    std::vector<char> l_shaderErrorMessage(l_infoLogLength + 1);
    glGetShaderInfoLog(id, l_infoLogLength, NULL, &l_shaderErrorMessage[0]);
    LOG_ERROR(std::string(l_shaderErrorMessage.begin(), l_shaderErrorMessage.end()).c_str());
  }
}

const std::string loadShader(const std::string path) {
  std::string l_shaderCode;
  std::ifstream l_shaderStream(path, std::ios::in);

  if (l_shaderStream.is_open()) {
    std::string l_line = "";
    while (getline(l_shaderStream, l_line))
      l_shaderCode += "\n" + l_line;
    l_shaderStream.close();
  }

  return l_shaderCode;
}

Shader::Shader() {
  auto l_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  auto l_vertexShaderCode = loadShader("./resources/vertex.glsl");
  compileShader(l_vertexShaderCode, l_vertexShaderID);
  
  auto l_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
  auto l_fragmentShaderCode = loadShader("./resources/fragment.glsl");
  compileShader(l_fragmentShaderCode, l_fragmentShaderID);

  m_programID = glCreateProgram();
  glAttachShader(m_programID, l_vertexShaderID);
  glAttachShader(m_programID, l_fragmentShaderID);
  glLinkProgram(m_programID);

  LOG_INFO("Linking program\n");
  GLint l_result = GL_FALSE;
  int l_infoLogLength;

  glGetProgramiv(m_programID, GL_LINK_STATUS, &l_result);
  glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &l_infoLogLength);
  if (l_infoLogLength > 0) {
    std::vector<char> l_programErrorMessage(l_infoLogLength + 1);
    glGetProgramInfoLog(m_programID, l_infoLogLength, NULL, &l_programErrorMessage[0]);
    LOG_ERROR(std::string(l_programErrorMessage.begin(), l_programErrorMessage.end()).c_str());
  }

  glDetachShader(m_programID, l_vertexShaderID);
  glDetachShader(m_programID, l_fragmentShaderID);

  glDeleteShader(l_vertexShaderID);
  glDeleteShader(l_fragmentShaderID);
}
