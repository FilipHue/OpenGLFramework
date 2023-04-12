#pragma once

#include "src/components/scene/scene.h"

class Demo : public Scene
{
public:
	Demo();

public:
	double lightX, lightY, lightZ;
	double lightMoveSpeed;

private:
	void Init();
	void StartFrame();
	void Update(double delta_time);
	void EndFrame();

	void OnInputUpdate(double delta_time, int mods);
	void OnKeyPress(int key, int mods);
	void OnKeyRelease(int key, int mods);
	void OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y);
	void OnMouseButtonPress(double x_pos, double y_pos, int key, int mods);
	void OnMouseButttonRelease(double x_pos, double y_pos, int key, int mods);
	void OnMouseScroll(double x_offset, double y_offset);
};
