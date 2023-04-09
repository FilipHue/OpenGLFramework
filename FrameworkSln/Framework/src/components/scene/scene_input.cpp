#include "scene_input.h"

SceneInput::SceneInput(Scene* scene)
{
	this->scene = scene;
	toogle_wireframe = false;
}

void SceneInput::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_F1) {
		if (toogle_wireframe == false) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		toogle_wireframe = !toogle_wireframe;
	}

	if (key == GLFW_KEY_ESCAPE) {
		scene->Exit();
	}
}

void SceneInput::OnInputUpdate(double deltaTime, int mods)
{
}

void SceneInput::OnKeyRelease(int key, int mods)
{
}

void SceneInput::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
}

void SceneInput::OnMouseButtonPress(double mouseX, double mouseY, int button, int mods)
{
}

void SceneInput::OnMouseButttonRelease(double mouseX, double mouseY, int button, int mods)
{
}

void SceneInput::OnMouseScroll(double x_offset, double y_offset)
{
}
