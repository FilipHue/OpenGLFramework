#pragma once

#include "engine/components/scene/scene.h"

class Test : public Scene
{
public:
	Test();
	~Test();

public:
	float lightX, lightY, lightZ;
	float lightMoveSpeed;

private:
	void Init() override;

	void StartFrame() override;
	void Update(double delta_time) override;
	void EndFrame() override;

	void OnInputUpdate(double deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;

	void OnMouseMove(double mouseX, double mouseY, double deltaX, double deltaY) override;
	void OnMouseButtonPress(double mouseX, double mouseY, int button, int mods) override;
	void OnMouseButttonRelease(double mouseX, double mouseY, int button, int mods) override;
	void OnMouseScroll(double mouseX, double mouseY, double deltaX, double deltaY) override;

	void OnWindowResize(int width, int height) override;

private:
	bool wireframe = false;
};
