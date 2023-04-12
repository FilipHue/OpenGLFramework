#include "shader.h"

Shader::Shader(const char* vertex_shader_path, const char* fragment_shader_path)
{
	// Get the vertex and fragment shader source code
	std::string vertex_shader_code;
	std::ifstream vertex_shader_file;
	std::string fragment_shader_code;
	std::ifstream fragment_shader_file;

	vertex_shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragment_shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vertex_shader_file.open(vertex_shader_path);
		fragment_shader_file.open(fragment_shader_path);

		std::stringstream vertex_shader_stream;
		std::stringstream fragment_shader_stream;

		vertex_shader_stream << vertex_shader_file.rdbuf();
		fragment_shader_stream << fragment_shader_file.rdbuf();

		vertex_shader_file.close();
		fragment_shader_file.close();

		vertex_shader_code = vertex_shader_stream.str();
		fragment_shader_code = fragment_shader_stream.str();
	}
	catch (std::ifstream::failure e)
	{
		SHADER_ERROR("SHADER FILE NOT SUCCESFULLY READ");
	}
	vertex_code = vertex_shader_code.c_str();
	fragment_code = fragment_shader_code.c_str();

	// Compile shaders
	unsigned int vertex_shader, fragment_shader;
	int success;
	char infoLog[512];

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_code, NULL);
	glCompileShader(vertex_shader);
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
		SHADER_ERROR("VERTEX SHADER COMPILATION FAILED\n{}", infoLog);
	}

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_code, NULL);
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
		SHADER_ERROR("FRAGMENT SHADER COMPILATION FAILED\n{}", infoLog);
	}

	shaderID = glCreateProgram();
	glAttachShader(shaderID, vertex_shader);
	glAttachShader(shaderID, fragment_shader);
	glLinkProgram(shaderID);
	glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
	if (!success)
	{
		SHADER_ERROR("SHADER PROGRAM LINKING FAILED");
	}

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
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
