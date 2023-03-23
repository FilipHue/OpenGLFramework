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

void ShapeManager::CreateRectangleX(const char* name, float width, float height)
{
	std::vector<VertexFormat> verticies{
		VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), GREY, glm::vec2(0, 0)),
		VertexFormat(glm::vec3(0, width, 0), glm::vec3(0, 1, 0), GREY, glm::vec2(1, 0)),
		VertexFormat(glm::vec3(0, width, height), glm::vec3(0, 1, 0), GREY, glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, 0, height), glm::vec3(0, 1, 0), GREY, glm::vec2(0, 1))
	};

	std::vector<unsigned int> indices{
		0, 1, 2,
		0, 2, 3
	};

	scene->CreateMesh(name, verticies, indices);
}

void ShapeManager::CreateRectangleY(const char* name, float width, float height)
{
	std::vector<VertexFormat> verticies{
		VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), GREY, glm::vec2(0, 0)),
		VertexFormat(glm::vec3(width, 0, 0), glm::vec3(0, 1, 0), GREY, glm::vec2(1, 0)),
		VertexFormat(glm::vec3(width, height, 0), glm::vec3(0, 1, 0), GREY, glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, height, 0), glm::vec3(0, 1, 0), GREY, glm::vec2(0, 1))
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
		VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), GREY, glm::vec2(0, 0)),
		VertexFormat(glm::vec3(width, 0, 0), glm::vec3(0, 1, 0), GREY, glm::vec2(1, 0)),
		VertexFormat(glm::vec3(width, 0, height), glm::vec3(0, 1, 0), GREY, glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, 0, height), glm::vec3(0, 1, 0), GREY, glm::vec2(0, 1))
	};

	std::vector<unsigned int> indices{
		0, 1, 2,
		0, 2, 3
	};

	scene->CreateMesh(name, verticies, indices);
}

void ShapeManager::CreateTriangleX(const char* name, float sideA, float sideB, float sideC, glm::vec3 startPosition = glm::vec3(0))
{
	if ((sideA + sideB < sideC) || (sideA + sideC < sideB) || (sideB + sideC < sideA)) {
		RENDER_WARN("Triangle doesn't respect the rule, you dummy");
		return;
	}
}

void ShapeManager::CreateTriangleY(const char* name, float sideA, float sideB, float sideC, glm::vec3 startPosition)
{
}

void ShapeManager::CreateTriangleZ(const char* name, float sideA, float sideB, float sideC, glm::vec3 startPosition)
{
}

void ShapeManager::CreateCube(const char* name, float width, float height, float length)
{
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), GREY),
		VertexFormat(glm::vec3(width, 0, 0), glm::vec3(0, 1, 0), GREY, glm::vec2(1, 0)),
		VertexFormat(glm::vec3(width, height ,0), glm::vec3(0, 1, 0), GREY, glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, height, 0), glm::vec3(0, 1, 0), GREY, glm::vec2(0, 1)),
		VertexFormat(glm::vec3(0, 0, length), glm::vec3(0, 1, 0), GREY),
		VertexFormat(glm::vec3(width, 0, length), glm::vec3(0, 1, 0), GREY, glm::vec2(1, 0)),
		VertexFormat(glm::vec3(width, height ,length), glm::vec3(0, 1, 0), GREY, glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, height, length), glm::vec3(0, 1, 0), GREY, glm::vec2(0, 1)),
	};

	std::vector<unsigned int> indices = {
		0, 1, 2,
		0, 2, 3,
		0, 4, 7,
		0, 7, 3,
		0, 1, 5,
		0, 5, 4,
		1, 5, 6,
		1, 6, 2,
		3, 2, 6,
		3, 6, 7,
		4, 5, 6,
		4, 6, 7
	};

	scene->CreateMesh(name, vertices, indices);
}
