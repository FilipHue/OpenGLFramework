#pragma once

#include <iostream>

typedef struct material Material;
struct material {
	const char* name;

	float ambient;
	float diffuse;
	float specular;
	float shininess;

	friend std::ostream& operator<<(std::ostream& os, const Material& m) {
		os << "Name: " << m.name << std::endl << "Ambient: " << m.ambient << std::endl << "Diffuse: " << m.diffuse << std::endl << "Specular: " << m.specular << std::endl << "Shininess: " << m.shininess;

		return os;
	};
};
