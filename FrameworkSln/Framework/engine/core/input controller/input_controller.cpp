#include "input_controller.h"
#include "../engine.h"

InputController::InputController()
{
	window = Engine::GetWindow();
	window->SubscribeToEvents(this);
}

InputController::~InputController()
{
}

void InputController::SetOn()
{
	window->SubscribeToEvents(this);
}

void InputController::SetOff()
{
	window->UnsubscribeFromEvents(this);
}
