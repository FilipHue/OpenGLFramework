#pragma once

#include <core.h>

class Shader
{
public:
	/**
	  * Constructor for shader class
	  * @param vertex_shader_path Is the path for the vertex shader
	  * @param fragment_shader_path Is the path for the fragment shader
	  */
	Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
	~Shader();

	/**
	  * It enables openGL to use this shader program 
	  */
	void Use();

	/**
	  * The next functions send the respective value at the respective location in the shader
	  * @param name The name of the variable in the shader
	  * @param value The value that is being sent
	  */

	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;

	void SetVec2(const std::string& name, glm::vec2& value) const;
	void SetVec3(const std::string& name, glm::vec3& value) const;
	void SetVec4(const std::string& name, glm::vec4& value) const;

	void SetMat2(const std::string& name, glm::mat2& value) const;
	void SetMat3(const std::string& name, glm::mat3& value) const;
	void SetMat4(const std::string& name, glm::mat4& value) const;

public:
	unsigned int shaderID;

private:
	const char* vertexCode;
	const char* fragmentCode;
};

