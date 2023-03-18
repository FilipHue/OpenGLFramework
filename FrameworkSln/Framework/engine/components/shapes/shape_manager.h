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
	  * Creates a rectangle on the XOY plane
	  * @param name The name of the rectangle object
	  * @param width The width of the rectangle
	  * @param height The height of the ractangle
	  */
	void CreateRectangleY(const char* name, float width, float height);
	/**
	  * Creates a rectangle on the XOZ plane
	  * @param name The name of the rectangle object
	  * @param width The width of the rectangle
	  * @param height The height of the ractangle
	  */
	void CreateRectangleZ(const char* name, float width, float height);

public:
	Scene* scene;
};
