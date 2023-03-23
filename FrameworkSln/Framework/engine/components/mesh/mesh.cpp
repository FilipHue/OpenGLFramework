#include "mesh.h"

Mesh::Mesh(
	std::string mesh_id,
	unsigned int VAO,
	std::vector<VertexFormat>& vertices,
	std::vector<unsigned int>& indices,
	Material* material
) : mesh_id(mesh_id), VAO(VAO), vertices(vertices), indices(indices), material(material) {}

Mesh::~Mesh()
{
}

const char* Mesh::GetMeshId() const
{
	return mesh_id.c_str();
}

const unsigned int Mesh::GetVAO() const
{
	return VAO;
}

const std::vector<VertexFormat> Mesh::GetVertices() const
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
