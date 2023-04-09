#pragma once

#include "window.h"

#include "glad/glad.h"
#include "glfw3.h"

class WindowCallbacks
{
	friend class Window;

public:
	WindowCallbacks() = delete;

private:
	/**
	 * @brief			Method for handling keyboard input
	 * @brief			See https://www.glfw.org/docs/latest/input_guide.html#input_keyboard for more information
	 * @param window	The context of the polling event
	 * @param key		The code of the pressed key
	 * @param scancode	The code of the pressed key, regardless of whether it has a key token
	 * @param action	The code of the state of the key (GLFW_PRESS, GLFW_RELEASE, GLFW_REPEAT)
	 * @param mods		The code of combination presses with special keys (L_SHIFT, L_ALT, L_CTRL, R_SHIFT, R_ALT, R_CTRL)
	*/
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	/**
	 * @brief			Method for handling mouse button input
	 * @brief			See https://www.glfw.org/docs/latest/input_guide.html#input_mouse_button for more information
	 * @param window	The context of the polling event
	 * @param button	The code of the mouse button pressed
	 * @param action	The code of the state of the mouse button (GLFW_PRESS, GLFW_RELEASE)
	 * @param mods		The code of combination presses with special keys (L_SHIFT, L_ALT, L_CTRL, R_SHIFT, R_ALT, R_CTRL)
	*/
	static void MousePress(GLFWwindow* window, int button, int action, int mods);
	/**
	 * @brief			Method for handling mouse movement
	 * @brief			See https://www.glfw.org/docs/latest/input_guide.html#cursor_pos for more information
	 * @param window	The context of the polling event
	 * @param x_pos		The cursor OX position, measured in screen coordinates, relative to the top-left corner of the window content area
	 * @param y_pos		The cursor OY position, measured in screen coordinates, relative to the top-left corner of the window content area
	*/
	static void MouseMove(GLFWwindow* window, double x_pos, double y_pos);
	/**
	 * @brief			Method for handling mouse scroll
	 * @brief			See https://www.glfw.org/docs/latest/input_guide.html#scrolling for more information
	 * @param window	The context of the polling event
	 * @param x_offset	The OX scroll offset (if supported)
	 * @param y_offset	The OY scroll offset
	*/
	static void MouseScroll(GLFWwindow* window, double x_offset, double y_offset);
};

