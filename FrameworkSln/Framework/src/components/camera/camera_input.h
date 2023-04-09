#pragma once

#include "camera.h"

#include "../../engine/core/input_controller/input_controller.h"

class CameraInput : public InputController
{
public:
	/**
	 * @brief			Method for attaching the camera controller to a camera object
	 * @param camera	The camera object to which the controller is attached to 
	*/
	CameraInput(Camera* camera);

private:
	void OnInputUpdate(double deltaTime, int mods) override;
	void OnKeyPress(int keys, int mods) override;
	void OnKeyRelease(int key, int mods) override;

	void OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y) override;
	void OnMouseButtonPress(double mouseX, double mouseY, int button, int mods) override;
	void OnMouseButttonRelease(double mouseX, double mouseY, int button, int mods) override;
	void OnMouseScroll(double x_offset, double y_offset) override;

private:
	Camera* camera;
};
