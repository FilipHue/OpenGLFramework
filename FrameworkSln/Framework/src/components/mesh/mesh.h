#pragma once

#include <core.h>

#include "../../utils/vertex.h"
#include "../../utils/material.h"

class Mesh
{
public:
	Mesh(
		std::string mesh_id,
		unsigned int VAO,
		std::vector<Vertex>& vertices,
		std::vector<unsigned int>& indices,
		Material* material = nullptr,
		bool has_error = false
	);

	const char* GetMeshId() const;
	const unsigned int GetVAO() const;
	const std::vector<Vertex> GetVertices() const;
	const std::vector<unsigned int> GetIndices() const;
	const Material* GetMaterial() const;

	const bool GetError() const;
	void HasError(bool error);

private:
	std::string mesh_id;

	unsigned int VAO;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	Material* material;

	bool has_error;
};
