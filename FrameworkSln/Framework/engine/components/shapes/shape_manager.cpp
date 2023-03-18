#include "shape_manager.h"

#include "../scene/scene.h"
#include "../texture/texture_manger.h"

ShapeManager::ShapeManager(Scene* scene)
{
	this->scene = scene;
}

ShapeManager::~ShapeManager()
{
}

void ShapeManager::CreateRectangleY(const char* name, float width, float height)
{
	std::vector<VertexFormat> verticies{
		VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), WHITE, glm::vec2(0, 0)),
		VertexFormat(glm::vec3(width, 0, 0), glm::vec3(0, 1, 0), WHITE, glm::vec2(1, 0)),
		VertexFormat(glm::vec3(width, height, 0), glm::vec3(0, 1, 0), WHITE, glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, height, 0), glm::vec3(0, 1, 0), WHITE, glm::vec2(0, 1))
	};

	std::vector<unsigned int> indices{
		0, 1, 2,
		0, 2, 3
	};

	scene->CreateMesh(name, verticies, indices);
}

void ShapeManager::CreateRectangleZ(const char* name, float width, float height)
{
	std::vector<VertexFormat> verticies{
		VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), WHITE, glm::vec2(0, 0)),
		VertexFormat(glm::vec3(width, 0, 0), glm::vec3(0, 1, 0), WHITE, glm::vec2(1, 0)),
		VertexFormat(glm::vec3(width, 0, height), glm::vec3(0, 1, 0), WHITE, glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, 0, height), glm::vec3(0, 1, 0), WHITE, glm::vec2(0, 1))
	};

	std::vector<unsigned int> indices{
		0, 1, 2,
		0, 2, 3
	};

	scene->CreateMesh(name, verticies, indices);
}
