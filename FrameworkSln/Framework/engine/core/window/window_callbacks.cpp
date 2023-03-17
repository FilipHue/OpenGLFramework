#include "window_callbacks.h"
#include "../engine.h"

void WindowCallbacks::OnClose(GLFWwindow* window)
{
}

void WindowCallbacks::OnResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, Engine::GetWindow()->resolution.x, Engine::GetWindow()->resolution.y);
}

void WindowCallbacks::OnError(int error, const char* description)
{
}

void WindowCallbacks::KeyCallbacks(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Engine::GetWindow()->KeyCallback(key, scancode, action, mods);
}

void WindowCallbacks::CursorMove(GLFWwindow* window, double mouseX, double mouseY)
{
	Engine::GetWindow()->MouseMoveCallback(mouseX, mouseY);
}

void WindowCallbacks::MouseClick(GLFWwindow* window, int button, int action, int mods)
{
	Engine::GetWindow()->MouseButtonCallbacks(button, action, mods);
}

void WindowCallbacks::ScrollMove(GLFWwindow* window, double scrollOffsetX, double scrollOffsetY)
{
	Engine::GetWindow()->MouseScrollCallback(scrollOffsetX, scrollOffsetY);
}
