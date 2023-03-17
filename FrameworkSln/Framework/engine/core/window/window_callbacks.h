#pragma once

#include <core.h>

class WindowCallbacks
{
public:
	/**
	  * Callback function for window close event
	  * @param window The current window
	  */
	static void OnClose(GLFWwindow* window);
	/**
	  * Callback function for window resize event
	  * @param window The current window
	  * @param width The new width of the window
	  * @param height The new height of the window
	  */
	static void OnResize(GLFWwindow* window, int width, int height);
	/**
	  * Callback function when an error occurs
	  * @param error Error code
	  * @param description The description of the error
	  */
	static void OnError(int error, const char* description);

	/**
	  * Callback function for keyboard events
	  * Check - https://www.glfw.org/docs/3.3/input_guide.html#input_key - for more information
	  * @param window The current window
	  * @param key The key pressed
	  * @param scancode The scancode of the key
	  * @param action Stores the action of the key, can be of type GL_PRESS, GL_REPEAT or GL_RELEASE
	  * @param mods Stores the combination of special key presses (SHIFT, ALT, TAB etc.)
	  */
	static void KeyCallbacks(GLFWwindow* window, int key, int scancode, int action, int mods);
	/**
	  * Callback function for mouse button events
	  * Check - https://www.glfw.org/docs/3.3/input_guide.html#input_mouse_button - for more information
	  * @param window The current window
	  * @param button The mouse button pressed
	  * @param action Stores the action of the mouse button, can be of type GL_PRESS or GL_RELEASE
	  * @param mods Stores the combination of special keys (SHIFT, ALT, TAB etc.)
	  */
	static void MouseClick(GLFWwindow* window, int button, int action, int mods);
	/**
	  * Callback function for mouse move event
	  * Check - https://www.glfw.org/docs/3.3/input_guide.html#cursor_pos - for more information
	  * @param window The current window
	  * @param mouseX Position on the OX axis of the mouse cursor
	  * @param mouseY Position on the OY axis of the mouse cursor
	  */
	static void CursorMove(GLFWwindow* window, double mouseX, double mouseY);
	/**
	  * Callback function for mouse scroll event
	  * Check - https://www.glfw.org/docs/3.3/input_guide.html#scrolling - for more information
	  * @param window The current window
	  * @param scrollOffsetX Offset on the OX axis
	  * @param scrollOffsetY Offset on the OY axis
	  */
	static void ScrollMove(GLFWwindow* window, double scrollOffsetX, double scrollOffsetY);

};
