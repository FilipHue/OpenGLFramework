#pragma once

#include <core.h>

#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>




class Shader
{
public:
	/**
	 * @brief						Class constructor
	 * @param vertext_shader_path		The vertex shader file path
	 * @param fragment_shader_path	The fragment shader file path
	*/	
	Shader(const char* vertex_shader_path, const char* fragment_shader_path);

	/**
	  * It enables openGL to use this shader program
	  */
	void Use();

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
	const char* vertex_code;
	const char* fragment_code;
};
