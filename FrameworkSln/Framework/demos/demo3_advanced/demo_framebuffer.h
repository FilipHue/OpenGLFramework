#pragma once

#include "../../src/components/scene/scene.h"

class DemoFramebuffer : public Scene
{
public:
	DemoFramebuffer();

public:
	unsigned int fbo;
	unsigned int textureColorbuffer;
	unsigned int rbo;

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

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

