#pragma once

#include <core.h>

#include "../scene/scene.h"
#include "../texture/texture_manger.h"

class ShapeManager
{
	friend class Scene;

public:
	ShapeManager(Scene* scene);
	~ShapeManager();

	/**
	  * Methods for creating a rectangle on the YOZ, XOZ and XOZ planes
	  * The object has a normal ([0, 1, 0]), a colour (WHITE) and texture coords
	  * @param name The name of the object
	  * @param width The width of the rectangle
	  * @param height The height of the rectangle
	  */

	void CreateRectangleX(const char* name, float width, float height);
	void CreateRectangleY(const char* name, float width, float height);
	void CreateRectangleZ(const char* name, float width, float height);

	/**
	  * Methods for creating a triangle on the YOZ, XOZ and XOZ planes
	  * The object has a normal ([0, 1, 0]), a colour (WHITE) and texture coords
	  * The sides are in the trigonometric order
	  * @param name The name of the object
	  * @param width The width of the rectangle
	  * @param height The height of the rectangle
	  */

	void CreateTriangleX(const char* name, float sideA, float sideB, float sideC, glm::vec3 startPosition);
	void CreateTriangleY(const char* name, float sideA, float sideB, float sideC, glm::vec3 startPosition);
	void CreateTriangleZ(const char* name, float sideA, float sideB, float sideC, glm::vec3 startPosition);

	/**
	  * Method for creating a cube (or a 6 sided prism)
	  * The object has a normal per vertex ([0, 1, 0]), a colour (GREY) and texture coords
	  * @param name The name of the object
	  * @param width The width of the cube
	  * @param height The height of the cube
	  * @param length The length of the cube
	  */
	void CreateCube(const char* name, float width, float height, float length);


private:
	Scene* scene;
};
