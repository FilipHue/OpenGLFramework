#include "input_controller.h"

InputController::InputController()
{
	b_is_active = true;
	Window::SubscribeToEvents(this);
}

InputController::~InputController()
{
}

void InputController::ToogleEvents()
{
	b_is_active = !b_is_active;
	b_is_active ? Window::SubscribeToEvents(this) : Window::UnsubscribeFromEvents(this);
}

bool InputController::IsActive()
{
	return b_is_active;
}
