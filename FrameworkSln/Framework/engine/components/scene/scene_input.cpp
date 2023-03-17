#include "scene_input.h"
#include "scene.h"

SceneInput::SceneInput(World* scene)
{
	this->scene = scene;
	toogleWireframe = false;
}

SceneInput::~SceneInput()
{
}

void SceneInput::OnInputUpdate(double deltaTime, int mods)
{
}

void SceneInput::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_F1) {
		if (toogleWireframe == false) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		toogleWireframe = !toogleWireframe;
	}

	if (key == GLFW_KEY_ESCAPE) {
		scene->Exit();
	}
}

void SceneInput::OnKeyRelease(int key, int mods)
{
}

void SceneInput::OnMouseMove(double mouseX, double mouseY, double deltaX, double deltaY)
{
}

void SceneInput::OnMouseButtonPress(double mouseX, double mouseY, int button, int mods)
{
}

void SceneInput::OnMouseButttonRelease(double mouseX, double mouseY, int button, int mods)
{
}

void SceneInput::OnMouseScroll(double mouseX, double mouseY, double deltaX, double deltaY)
{
}

void SceneInput::OnWindowResize(int width, int height)
{
}
