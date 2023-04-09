#include "mesh.h"

Mesh::Mesh(
	std::string mesh_id,
	unsigned int VAO,
	std::vector<Vertex>& vertices,
	std::vector<unsigned int>& indices,
	Material* material,
	bool has_error
) : mesh_id(mesh_id), VAO(VAO), vertices(vertices), indices(indices), material(material), has_error(has_error) {}

const char* Mesh::GetMeshId() const
{
	return mesh_id.c_str();
}

const unsigned int Mesh::GetVAO() const
{
	return VAO;
}

const std::vector<Vertex> Mesh::GetVertices() const
{
	return vertices;
}

const std::vector<unsigned int> Mesh::GetIndices() const
{
	return indices;
}

const Material* Mesh::GetMaterial() const
{
	return material;
}

const bool Mesh::GetError() const
{
	return has_error;
}

void Mesh::HasError(bool error)
{
	has_error = error;
}
