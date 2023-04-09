#pragma once

#include "../../utils/vertex.h"

#include "../../components/scene/scene.h"
#include "../texture/texture_manager.h"

class ShapeManager
{
	friend class Scene;

public:
	ShapeManager(Scene* scene);

	void CreateRectangleX(const char* name, float width, float height);
	void CreateRectangleY(const char* name, float width, float height);
	void CreateRectangleZ(const char* name, float width, float height);

	void CreateTriangleX(const char* name, float sideA, float sideB, float sideC, glm::vec3 startPosition);
	void CreateTriangleY(const char* name, float sideA, float sideB, float sideC, glm::vec3 startPosition);
	void CreateTriangleZ(const char* name, float sideA, float sideB, float sideC, glm::vec3 startPosition);

	void CreateCube(const char* name, float width, float height, float length);

private:
	Scene* scene;
	Material* defaultMaterial;
};
