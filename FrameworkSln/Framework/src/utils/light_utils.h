#pragma once

#include <glm.hpp>

typedef struct light_properties LightProperties;
struct light_properties {
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 colour;

	glm::vec3 Ka;
	glm::vec3 Kd;
	glm::vec3 Ksp;
	float Ksh;

	float Kc;
	float Kl;
	float Kq;

	float in_cutoff_angle;
	float out_cutoff_angle;

	light_properties(
		glm::vec3 position,
		glm::vec3 direction,
		glm::vec3 colour,

		glm::vec3 Ka = glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3 Kd = glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3 Ksp = glm::vec3(1.0f, 1.0f, 1.0f),
		float Ksh = 32.0f,

		float Kc = 1.0f,
		float Kl = 0.0f,
		float Kq = 0.0f,

		float in_cutoff_angle = 0.0f,
		float out_cutoff_angle = 0.0f
	) : position(position), direction(direction), colour(colour),
		Ka(Ka), Kd(Kd), Ksp(Ksp), Ksh(Ksh),
		Kc(Kc), Kl(Kl), Kq(Kq),
		in_cutoff_angle(in_cutoff_angle), out_cutoff_angle(out_cutoff_angle) {}
};
