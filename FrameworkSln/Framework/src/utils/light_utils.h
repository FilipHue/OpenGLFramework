#pragma once

#include <glm.hpp>

typedef struct light_properties LightProperties;
struct light_properties {
	glm::vec3 position;
	glm::vec3 colour;

	glm::vec3 Ka;
	glm::vec3 Kd;
	glm::vec3 Ksp;
	float Ksh;

	light_properties(
		glm::vec3 position,
		glm::vec3 colour,
		glm::vec3 Ka = glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3 Kd = glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3 Ksp = glm::vec3(1.0f, 1.0f, 1.0f),
		float Ksh = 32.0f
	) : position(position), colour(colour), Ka(Ka), Kd(Kd), Ksp(Ksp), Ksh(Ksh) {}
};
