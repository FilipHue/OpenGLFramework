#pragma once

#include <colour.h>
#include <glm.hpp>

struct VertexFormat {
	VertexFormat(
		glm::vec3 position,
		glm::vec3 normal = glm::vec3(0, 1, 0),
		Colour colour = WHITE,
		glm::vec2 textureCoords = glm::vec2(0)
	) : position(position), normal(normal), colour(colour), textureCoords(textureCoords) {}

	glm::vec3 position;
	glm::vec3 normal;
	Colour colour;
	glm::vec2 textureCoords;
};
