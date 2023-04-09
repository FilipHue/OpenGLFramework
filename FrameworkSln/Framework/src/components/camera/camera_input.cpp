#include "camera_input.h"
#include "../../engine/engine.h"

CameraInput::CameraInput(Camera* camera)
{
	this->camera = camera;
}

void CameraInput::OnInputUpdate(double deltaTime, int mods)
{
	if (Engine::GetWindow()->GetContinousPress(GLFW_KEY_W)) {
		camera->MoveForward(deltaTime);
	}

	if (Engine::GetWindow()->GetContinousPress(GLFW_KEY_S)) {
		camera->MoveBackwards(deltaTime);
	}

	if (Engine::GetWindow()->GetContinousPress(GLFW_KEY_A)) {
		camera->MoveLeft(deltaTime);
	}

	if (Engine::GetWindow()->GetContinousPress(GLFW_KEY_D)) {
		camera->MoveRight(deltaTime);
	}

	if (Engine::GetWindow()->GetContinousPress(GLFW_KEY_Q)) {
		camera->MoveUp(deltaTime);
	}

	if (Engine::GetWindow()->GetContinousPress(GLFW_KEY_E)) {
		camera->MoveDown(deltaTime);
	}
}

void CameraInput::OnKeyPress(int key, int mods)
{
}

void CameraInput::OnKeyRelease(int key, int mods)
{
}

void CameraInput::OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y)
{
	camera->RotateOX(-delta_y * camera->GetCameraSensitivity());
	camera->RotateOY(-delta_x * camera->GetCameraSensitivity());
}

void CameraInput::OnMouseButtonPress(double mouseX, double mouseY, int button, int mods)
{
}

void CameraInput::OnMouseButttonRelease(double mouseX, double mouseY, int button, int mods)
{
}

void CameraInput::OnMouseScroll(double x_offset, double y_offset)
{
}
