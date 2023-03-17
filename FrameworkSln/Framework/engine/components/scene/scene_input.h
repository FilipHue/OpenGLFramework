#pragma once

#include "../core/input controller/input_controller.h"
#include "scene.h"

class SceneInput : public InputController
{
public:
	/**
	  * Constructor for the Scene Input class
	  * Binds a controller to the scene
	  * (Couldn't pass a Scene object, may be because Scene is a derived class of World, should investigate in the future)
	  * @param scene The scene to which the controller is binded to
	  */
	SceneInput(World* scene);
	~SceneInput();

	/**
	  * The methods bellow are overrides for the methods in the Input Controller class 
	  */

	void OnKeyPress(int key, int mods) override;

private:
	void OnInputUpdate(double deltaTime, int mods) override;
	void OnKeyRelease(int key, int mods) override;

	void OnMouseMove(double mouseX, double mouseY, double deltaX, double deltaY) override;
	void OnMouseButtonPress(double mouseX, double mouseY, int button, int mods) override;
	void OnMouseButttonRelease(double mouseX, double mouseY, int button, int mods) override;
	void OnMouseScroll(double mouseX, double mouseY, double deltaX, double deltaY) override;

	void OnWindowResize(int width, int height) override;

private:
	World* scene;
	bool toogleWireframe;
};
