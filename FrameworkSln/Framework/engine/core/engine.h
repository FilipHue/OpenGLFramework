#pragma once

#include "window/window.h"

class Engine
{
public:
	/**
	  * The constructor is disabled since we don't want to create an Engine type object
	  * This is like a container that has the created window and can return the time
	  */
	Engine() = delete;

	/**
	  * The functions created and returns the active window
	  * @param wp It's a structure of type WindowProperties used in the window creation
	  */
	static Window* Init(WindowProperties wp);
	/**
	  * Returns the active window 
	  */
	static Window* GetWindow();
	/**
	  * Returns the time since the library was initialized with glfwInit
	  * Check - https://www.glfw.org/docs/3.3/input_guide.html#time - for more information
	  */
	static double GetElapsedTime();
	/**
	  * Exits the engine and terminates the GLFW library
	  * Check - https://www.glfw.org/docs/3.3/group__init.html#gaaae48c0a18607ea4a4ba951d939f0901 - for more information
	  */
	static void Exit();

private:
	static Window* gameWindow;
};
