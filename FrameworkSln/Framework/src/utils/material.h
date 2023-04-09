#pragma once

#include <iostream>
#include <glm.hpp>

typedef struct material Material;
struct material {
	const char* name;

	glm::vec3 Ka;
	glm::vec3 Kd;
	glm::vec3 Ksp;
	float Ksh;

	friend std::ostream& operator<<(std::ostream& os, const Material& m) {
		os << "Name: " << m.name << std::endl << "Ambient: " << m.Ka << std::endl << "Diffuse: " << m.Kd << std::endl << "Specular: " << m.Ksp << std::endl << "Shininess: " << m.Ksh;

		return os;
	};
};