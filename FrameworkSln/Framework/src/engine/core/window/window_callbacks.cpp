#include "window_callbacks.h"

void WindowCallbacks::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window::KeyCallbacks(key, scancode, action, mods);
}

void WindowCallbacks::MousePress(GLFWwindow* window, int button, int action, int mods)
{
	Window::MouseButtonCallbacks(button, action, mods);
}

void WindowCallbacks::MouseMove(GLFWwindow* window, double x_pos, double y_pos)
{
	Window::MouseMoveCallbacks(x_pos, y_pos);
}

void WindowCallbacks::MouseScroll(GLFWwindow* window, double x_offset, double y_offset)
{
	Window::MouseScrollCallbacks(x_offset, y_offset);
}
