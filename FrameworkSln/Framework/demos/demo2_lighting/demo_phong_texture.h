#pragma once

#include "../../src/components/scene/scene.h"

class DemoPhongTexture : public Scene
{
public:
	double lightX, lightY, lightZ;
	double lightMoveSpeed;

	glm::mat4 model_matrix;
	Light* light;

private:
	void Init() override;
	void StartFrame() override;
	void Update(double delta_time) override;
	void EndFrame() override;

	void OnInputUpdate(double delta_time, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y) override;
	void OnMouseButtonPress(double x_pos, double y_pos, int key, int mods) override;
	void OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods) override;
	void OnMouseScroll(double x_offset, double y_offset) override;
};

