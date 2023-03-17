#include "camera_input.h"
#include "../../world.h"

CameraInput::CameraInput(Camera* camera)
{
	this->camera = camera;
}

CameraInput::~CameraInput()
{
}

void CameraInput::OnInputUpdate(double deltaTime, int mods)
{
	if (window->GetKeyState(GLFW_KEY_W)) {
		camera->MoveForward(deltaTime);
	}

	if (window->GetKeyState(GLFW_KEY_S)) {
		camera->MoveBackwards(deltaTime);
	}

	if (window->GetKeyState(GLFW_KEY_A)) {
		camera->MoveLeft(deltaTime);
	}

	if (window->GetKeyState(GLFW_KEY_D)) {
		camera->MoveRight(deltaTime);
	}

	if (window->GetKeyState(GLFW_KEY_Q)) {
		camera->MoveUp(deltaTime);
	}

	if (window->GetKeyState(GLFW_KEY_E)) {
		camera->MoveDown(deltaTime);
	}
}

void CameraInput::OnKeyPress(int key, int mods)
{
}

void CameraInput::OnKeyRelease(int key, int mods)
{
}

void CameraInput::OnMouseMove(double mouseX, double mouseY, double deltaX, double deltaY)
{
	camera->RotateOX(-deltaY * camera->mouseSensitivity);
	camera->RotateOY(-deltaX * camera->mouseSensitivity);
}

void CameraInput::OnMouseButtonPress(double mouseX, double mouseY, int button, int mods)
{
}

void CameraInput::OnMouseButttonRelease(double mouseX, double mouseY, int button, int mods)
{
}

void CameraInput::OnMouseScroll(double mouseX, double mouseY, double deltaX, double deltaY)
{
}

void CameraInput::OnWindowResize(int width, int height)
{
}
