#include "shape_manager.h"

ShapeManager::ShapeManager(Scene* scene)
{
	this->scene = scene;
	defaultMaterial = new Material;
	defaultMaterial->name = "default";
	defaultMaterial->Ka = glm::vec3(0.1, 0.1, 0.1);
	defaultMaterial->Kd = glm::vec3(0.2, 0.4, 0.3);
	defaultMaterial->Ksp = glm::vec3(0.5, 0.5, 0.5);
	defaultMaterial->Ksh = 0.7f;
}

void ShapeManager::CreateRectangleX(const char* name, float width, float height)
{
	std::vector<Vertex> verticies{
		Vertex(glm::vec3(0, 0, 0), GREY, glm::vec3(0, 1, 0), glm::vec2(0, 0)),
		Vertex(glm::vec3(0, width, 0), GREY, glm::vec3(0, 1, 0), glm::vec2(1, 0)),
		Vertex(glm::vec3(0, width, height), GREY, glm::vec3(0, 1, 0), glm::vec2(1, 1)),
		Vertex(glm::vec3(0, 0, height), GREY, glm::vec3(0, 1, 0), glm::vec2(0, 1))
	};

	std::vector<unsigned int> indices{
		0, 1, 2,
		0, 2, 3
	};

	scene->CreateMesh(name, verticies, indices, nullptr);
}

void ShapeManager::CreateRectangleY(const char* name, float width, float height)
{
	std::vector<Vertex> verticies{
		Vertex(glm::vec3(0, 0, 0), GREY, glm::vec3(0, 1, 0), glm::vec2(0, 0)),
		Vertex(glm::vec3(width, 0, 0), GREY, glm::vec3(0, 1, 0), glm::vec2(1, 0)),
		Vertex(glm::vec3(width, height, 0), GREY, glm::vec3(0, 1, 0), glm::vec2(1, 1)),
		Vertex(glm::vec3(0, height, 0), GREY, glm::vec3(0, 1, 0), glm::vec2(0, 1))
	};

	std::vector<unsigned int> indices{
		0, 1, 2,
		0, 2, 3
	};

	scene->CreateMesh(name, verticies, indices, nullptr);
}

void ShapeManager::CreateRectangleZ(const char* name, float width, float height)
{
	std::vector<Vertex> verticies{
		Vertex(glm::vec3(0, 0, 0), GREY, glm::vec3(0, 1, 0), glm::vec2(0, 0)),
		Vertex(glm::vec3(width, 0, 0), GREY, glm::vec3(0, 1, 0), glm::vec2(1, 0)),
		Vertex(glm::vec3(width, 0, height), GREY, glm::vec3(0, 1, 0), glm::vec2(1, 1)),
		Vertex(glm::vec3(0, 0, height), GREY, glm::vec3(0, 1, 0), glm::vec2(0, 1))
	};

	std::vector<unsigned int> indices{
		0, 1, 2,
		0, 2, 3
	};

	scene->CreateMesh(name, verticies, indices, nullptr);
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
	std::vector<Vertex> vertices = {
		Vertex(glm::vec3(0, 0, 0), GREY, glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(width, 0, 0), GREY, glm::vec3(0, 1, 0), glm::vec2(1, 0)),
		Vertex(glm::vec3(width, height ,0), GREY, glm::vec3(0, 1, 0), glm::vec2(1, 1)),
		Vertex(glm::vec3(0, height, 0), GREY, glm::vec3(0, 1, 0), glm::vec2(0, 1)),
		Vertex(glm::vec3(0, 0, length), GREY, glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(width, 0, length), GREY, glm::vec3(0, 1, 0), glm::vec2(1, 0)),
		Vertex(glm::vec3(width, height ,length), GREY, glm::vec3(0, 1, 0), glm::vec2(1, 1)),
		Vertex(glm::vec3(0, height, length), GREY, glm::vec3(0, 1, 0), glm::vec2(0, 1)),
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

	scene->CreateMesh(name, vertices, indices, defaultMaterial);
}
