#pragma once

#include "camera.h"

#include "../../core/input controller/input_controller.h"
#include "../core/engine.h"

class CameraInput : public InputController
{
public:
	/**
	  * Constructor for the camera controller
	  * @param camera The camera object to which the controller is binded to
	  */
	CameraInput(Camera* camera);
	~CameraInput();

private:
	/**
	  * Overrides to the functions from the InputController class 
	  */

	void OnInputUpdate(double deltaTime, int mods) override;
	void OnKeyPress(int keys, int mods) override;
	void OnKeyRelease(int key, int mods) override;

	void OnMouseMove(double mouseX, double mouseY, double deltaX, double deltaY) override;
	void OnMouseButtonPress(double mouseX, double mouseY, int button, int mods) override;
	void OnMouseButttonRelease(double mouseX, double mouseY, int button, int mods) override;
	void OnMouseScroll(double mouseX, double mouseY, double deltaX, double deltaY) override;

	void OnWindowResize(int width, int height) override;

private:
	Camera* camera;

};
