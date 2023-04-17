#pragma once

#include <glm.hpp>

#include "../../managers/shader/shader.h"

class Light
{
public:
	Light(
		glm::vec3 position, glm::vec3 colour,
		glm::vec3 Ka = glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3 Kd = glm::vec3(0.5f, 0.5f, 0.5f),
		glm::vec3 Ksp = glm::vec3(1.0f, 1.0f, 1.0f), float Ksh = 32.0f,
		std::string struct_name = "");

	virtual void SendToShader(Shader* shader);

public:
	glm::vec3 position;
	glm::vec3 colour;

	glm::vec3 Ka;
	glm::vec3 Kd;
	glm::vec3 Ksp;
	float Ksh;

protected:
	std::string struct_name;
};
