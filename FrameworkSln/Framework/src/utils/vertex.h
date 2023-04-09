#pragma once

#include <glm.hpp>

#include "colour.h"
#include "glm_utils.h"

typedef struct vertex Vertex;
struct vertex {
	glm::vec3 position;
	Colour colour;
	glm::vec3 normal;
	glm::vec2 textureCoords;

	vertex(
		glm::vec3 position,
		Colour colour = WHITE,
		glm::vec3 normal = glm::vec3(0, 1, 0),
		glm::vec2 textureCoords = glm::vec2(0)
	) : position(position), colour(colour), normal(normal), textureCoords(textureCoords) {}

	friend std::ostream& operator<<(std::ostream& os, const Vertex& v) {
		os <<
			"Position: " << v.position << std::endl <<
			"Normal: " << v.normal << std::endl <<
			"Colour: " << v.colour << std::endl <<
			"Texture Coords: " << v.textureCoords << std::endl;

		return os;
	};
};
