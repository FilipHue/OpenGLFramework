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
