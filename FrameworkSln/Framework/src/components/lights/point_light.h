#pragma once

#include "light.h"

class PointLight : public Light
{
public:
	PointLight(
		glm::vec3 position, glm::vec3 colour,
		glm::vec3 Ka = glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3 Kd = glm::vec3(0.5f, 0.5f, 0.5f),
		glm::vec3 Ksp = glm::vec3(1.0f, 1.0f, 1.0f), float Ksh = 32.0f,
		float Kc = 1.0f, float Kl = 0.09f, float Kq = 0.032f,
		std::string struct_name = "");

	void SendToShader(Shader* shader) override;

public:
	float Kc;
	float Kl;
	float Kq;
};

