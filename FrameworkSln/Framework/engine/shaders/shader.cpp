#include "shader.h"

#include <core.h>

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	// Get the vertex and fragment shader source code
	std::string vertexShaderCode;
	std::ifstream vertexShaderFile;
	std::string fragmentShaderCode;
	std::ifstream fragmentShaderFile;

	vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vertexShaderFile.open(vertexShaderPath);
		fragmentShaderFile.open(fragmentShaderPath);

		std::stringstream vertex_shader_stream;
		std::stringstream fragment_shader_stream;

		vertex_shader_stream << vertexShaderFile.rdbuf();
		fragment_shader_stream << fragmentShaderFile.rdbuf();

		vertexShaderFile.close();
		fragmentShaderFile.close();

		vertexShaderCode = vertex_shader_stream.str();
		fragmentShaderCode = fragment_shader_stream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR -> SHADER FILE NOT SUCCESFULLY READ" << std::endl;
	}
	vertexCode = vertexShaderCode.c_str();
	fragmentCode = fragmentShaderCode.c_str();

	// Compile shaders
	unsigned int vertexShader, fragmentShader;
	int success;
	char infoLog[512];

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexCode, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR! -> VERTEX SHADER COMPILATION FAILED!" << std::endl << infoLog << std::endl;
	}

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentCode, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR! -> FRAGMENT SHADER COMPILATION FAILED!" << std::endl << infoLog << std::endl;
	}

	shaderID = glCreateProgram();
	glAttachShader(shaderID, vertexShader);
	glAttachShader(shaderID, fragmentShader);
	glLinkProgram(shaderID);
	glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
	if (!success)
	{
		std::cout << "ERROR! -> SHADER PROGRAM LINKING FAILED" << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
}

void Shader::Use()
{
	glUseProgram(shaderID);
}

void Shader::SetBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(shaderID, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(shaderID, name.c_str()), value);
}

void Shader::SetVec2(const std::string& name, glm::vec2& value) const
{
	glUniform2fv(glGetUniformLocation(shaderID, name.c_str()), 1, glm::value_ptr(value));
}

void Shader::SetVec3(const std::string& name, glm::vec3& value) const
{
	glUniform3fv(glGetUniformLocation(shaderID, name.c_str()), 1, glm::value_ptr(value));
}

void Shader::SetVec4(const std::string& name, glm::vec4& value) const
{
	glUniform4fv(glGetUniformLocation(shaderID, name.c_str()), 1, glm::value_ptr(value));
}

void Shader::SetMat2(const std::string& name, glm::mat2& value) const
{
	glUniformMatrix2fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetMat3(const std::string& name, glm::mat3& value) const
{
	glUniformMatrix3fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetMat4(const std::string& name, glm::mat4& value) const
{
	glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}
