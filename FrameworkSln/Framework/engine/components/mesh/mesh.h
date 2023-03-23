#pragma once

#include <core.h>

#include <material.h>
#include <vertex_utils.h>

class Mesh
{
public:
	/**
	  * Constructor for the Mesh class
	  * @param mesh_id The name/id of the mesh object created
	  * @param VAO The VAO that the mesh object is binded to
	  * @param vertices The vertices of the mesh object
	  * @param indices The indices of for the mesh object
	  */
	Mesh(
		std::string mesh_id,
		unsigned int VAO,
		std::vector<VertexFormat> &vertices,
		std::vector<unsigned int> &indices,
		Material* material = nullptr
	);
	~Mesh();

	/**
	  * Returns the mesh id 
	  */
	const char* GetMeshId() const;
	/**
	  * Return the VAO of the mesh 
	  */
	const unsigned int GetVAO() const;
	/**
	  * Returns the vertices of the mesh 
	  */
	const std::vector<VertexFormat> GetVertices() const;
	/**
	  * Returns the indices of the mesh 
	  */
	const std::vector<unsigned int> GetIndices() const;
	/**
	  * Returns the material of the mesh 
	  */
	const Material* GetMaterial() const;

private:
	std::string mesh_id;

	unsigned int VAO;
	std::vector<VertexFormat> vertices;
	std::vector<unsigned int> indices;

	Material* material;
};

