#include "shape_manager.h"

ShapeManager::ShapeManager(Scene* scene)
{
	this->scene = scene;
	defaultMaterial = new Material;
	defaultMaterial->name = "default";
	defaultMaterial->Ka = glm::vec3(1.0f, 0.5f, 0.31f);
	defaultMaterial->Kd = glm::vec3(1.0f, 0.5f, 0.31f);
	defaultMaterial->Ksp = glm::vec3(0.5f, 0.5f, 0.5f);
	defaultMaterial->Ksh = 32.0f;
}

void ShapeManager::CreateRectangleX(const char* name, float width, float height)
{
	std::vector<Vertex> verticies{
		Vertex(glm::vec3(0, 0, 0),				GREY, glm::vec3(1, 0, 0),  glm::vec2(0, 0)),		// 0
		Vertex(glm::vec3(0, height, 0),			GREY, glm::vec3(1, 0, 0),  glm::vec2(1, 0)),		// 1
		Vertex(glm::vec3(0, height, width),		GREY, glm::vec3(1, 0, 0),  glm::vec2(1, 1)),		// 2
		Vertex(glm::vec3(0, 0, width),			GREY, glm::vec3(1, 0, 0),  glm::vec2(0, 1))			// 3
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
		Vertex(glm::vec3(0, 0, 0),				GREY, glm::vec3(0, 1, 0),  glm::vec2(0, 0)),		// 0
		Vertex(glm::vec3(width, 0, 0),			GREY, glm::vec3(0, 1, 0),  glm::vec2(1, 0)),		// 1
		Vertex(glm::vec3(width, 0, height),		GREY, glm::vec3(0, 1, 0),  glm::vec2(1, 1)),		// 2
		Vertex(glm::vec3(0, 0, height),			GREY, glm::vec3(0, 1, 0),  glm::vec2(0, 1))			// 3
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
		Vertex(glm::vec3(0, 0, 0),				GREY, glm::vec3(0, 0, -1), glm::vec2(0, 0)),		// 0
		Vertex(glm::vec3(width, 0, 0),			GREY, glm::vec3(0, 0, -1), glm::vec2(1, 0)),		// 1
		Vertex(glm::vec3(width, height, 0),		GREY, glm::vec3(0, 0, -1), glm::vec2(1, 1)),		// 2
		Vertex(glm::vec3(0, height, 0),			GREY, glm::vec3(0, 0, -1), glm::vec2(0, 1))			// 3
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
		Vertex(glm::vec3(0, 0, 0),					GREY, glm::vec3(0, 0, -1), glm::vec2(0, 0)),	// 0
		Vertex(glm::vec3(width, 0, 0),				GREY, glm::vec3(0, 0, -1), glm::vec2(1, 0)),	// 1
		Vertex(glm::vec3(width, height ,0),			GREY, glm::vec3(0, 0, -1), glm::vec2(1, 1)),	// 2
		Vertex(glm::vec3(0, height, 0),				GREY, glm::vec3(0, 0, -1), glm::vec2(0, 1)),	// 3

		Vertex(glm::vec3(0, 0, 0),					GREY, glm::vec3(-1, 0, 0), glm::vec2(0, 0)),	// 4
		Vertex(glm::vec3(0, 0, length),				GREY, glm::vec3(-1, 0, 0), glm::vec2(1, 0)),	// 5
		Vertex(glm::vec3(0, height, length),		GREY, glm::vec3(-1, 0, 0), glm::vec2(1, 1)),	// 6
		Vertex(glm::vec3(0, height, 0),				GREY, glm::vec3(-1, 0, 0), glm::vec2(0, 1)),	// 7 

		Vertex(glm::vec3(0, 0, length),				GREY, glm::vec3(0, 0, 1),  glm::vec2(0, 0)),	// 8
		Vertex(glm::vec3(width, 0, length),			GREY, glm::vec3(0, 0, 1),  glm::vec2(1, 0)),	// 9
		Vertex(glm::vec3(width, height, length),	GREY, glm::vec3(0, 0, 1),  glm::vec2(1, 1)),	// 10
		Vertex(glm::vec3(0, height, length),		GREY, glm::vec3(0, 0, 1),  glm::vec2(0, 1)),	// 11

		Vertex(glm::vec3(width, 0, length),			GREY, glm::vec3(1, 0, 0),  glm::vec2(0, 0)),	// 12
		Vertex(glm::vec3(width, 0, 0),				GREY, glm::vec3(1, 0, 0),  glm::vec2(1, 0)),	// 13
		Vertex(glm::vec3(width, height, 0),			GREY, glm::vec3(1, 0, 0),  glm::vec2(1, 1)),	// 14
		Vertex(glm::vec3(width, height, length),	GREY, glm::vec3(1, 0, 0),  glm::vec2(0, 1)),	// 15

		Vertex(glm::vec3(0, height, 0),				GREY, glm::vec3(0, 1, 0),  glm::vec2(0, 0)),	// 16
		Vertex(glm::vec3(width, height, 0),			GREY, glm::vec3(0, 1, 0),  glm::vec2(1, 0)),	// 17
		Vertex(glm::vec3(width, height, length),	GREY, glm::vec3(0, 1, 0),  glm::vec2(1, 1)),	// 18
		Vertex(glm::vec3(0, height, length),		GREY, glm::vec3(0, 1, 0),  glm::vec2(0, 1)),	// 19

		Vertex(glm::vec3(0, 0, 0),					GREY, glm::vec3(0, -1, 0), glm::vec2(0, 0)),    // 20
		Vertex(glm::vec3(width, 0, 0),				GREY, glm::vec3(0, -1, 0), glm::vec2(1, 0)),   	// 21
		Vertex(glm::vec3(width, 0, length),			GREY, glm::vec3(0, -1, 0), glm::vec2(1, 1)),    // 22
		Vertex(glm::vec3(0, 0, length),				GREY, glm::vec3(0, -1, 0), glm::vec2(0, 1))	    // 23
	};																						

	std::vector<unsigned int> indices = {
		0, 1, 2,
		0, 2, 3,

		4, 6, 5,
		4, 7, 6,

		8, 10, 9,
		8, 10, 11,

		12, 14, 13,
		12, 15, 14,

		16, 17, 18,
		16, 18, 19,

		20, 21, 22,
		20, 22, 23
	};

	scene->CreateMesh(name, vertices, indices, defaultMaterial);
}
