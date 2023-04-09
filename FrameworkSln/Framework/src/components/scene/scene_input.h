#pragma once

//#include "../../engine/core/input_controller/input_controller.h"
#include "scene.h"

class SceneInput : public InputController
{
	friend class Scene;

public:
	SceneInput(Scene* scene);

	void OnKeyPress(int key, int mods);

private:
	void OnInputUpdate(double deltaTime, int mods) override;
	void OnKeyRelease(int key, int mods) override;

	void OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y) override;
	void OnMouseButtonPress(double mouseX, double mouseY, int button, int mods) override;
	void OnMouseButttonRelease(double mouseX, double mouseY, int button, int mods) override;
	void OnMouseScroll(double x_offset, double y_offset) override;

private:
	Scene* scene;
	bool toogle_wireframe;
};

