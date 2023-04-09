#pragma once

#include <memory>
#include <list>

#include "core.h"
#include "glad/glad.h"
#include "glfw3.h"
#include "glm.hpp"

#include "window_properties.h"
#include "window_callbacks.h"
#include "../input_controller/input_controller.h"

class Window
{
	friend class WindowCallbacks;
	friend class InputController;

public:
	/**
	 * @brief			Method for initializing the glfw and glad library, setting window hints and creating the window context
	 * @param wp		Structure for window properties
	*/
	void Init(window_properties* wp);
	/**
	 * @brief			Method for terminating the window context
	*/
	void Shutdown();

	void PollEvents();
	void SwapBuffers();

	int ShouldClose();

	GLFWwindow* GetNativeWindow();

	/**
	 * @brief				Method for handling keyboard input
	 * @brief				See window_callbacks for more information
	*/
	static void KeyCallbacks(int key, int scancode, int action, int mods);
	/**
	 * @brief				Method for handling mouse button input
	 * @brief				See window_callbacks for more information
	*/
	static void MouseButtonCallbacks(int button, int action, int mods);
	/**
	 * @brief				Method for handling mouse movement
	 * @brief				See window_callbacks for more information
	*/
	static void MouseMoveCallbacks(double x_pos, double y_pos);
	/**
	 * @brief				Method for handling mouse scroll
	 * @brief				See window_callbacks for more information
	*/
	static void MouseScrollCallbacks(double x_offset, double y_offset);
	/**
	 * @brief				Method for handling continous events (continous key press, for example)
	 * @param delta_time	The time between the last frame and the current frame
	*/
	static void ContinousEvents(double delta_time);

	void SetWindowHints();
	void SetWindowCallbacks();

	void SetCursor(int x_pos, int y_pos);
	void CenterCursor();
	void ShowCursor();
	void HideCursor();
	void DisableCursor();

	void SetWindow(int x_pos, int y_pos);
	void CenterWindow();

	bool GetContinousPress(int key);

	/**
	 * @brief				Method for connecting an input controller to the current window (for "listening" to events)
	 * @param ic			The input controller that is being connected
	*/
	static void SubscribeToEvents(InputController* ic);
	/**
	 * @brief				Method for disconnecting an input controller from the current window
	 * @param ic			The input controller that is being disconnected
	*/
	static void UnsubscribeFromEvents(InputController* ic);

public:
	glm::ivec2 resolution;

private:
	window_properties* p_properties;

	GLFWwindow* p_native_window;
	GLFWmonitor* p_native_monitor;

	const GLFWvidmode* p_video_mode;
	bool b_should_close;

	static bool key_states[GLFW_KEY_LAST];
	static bool continous_key_events[GLFW_KEY_LAST];
	static int key_mods;

	static std::list<InputController*> input_controllers;

	static double mouse_x;
	static double mouse_y;
	static double mouse_delta_x;
	static double mouse_delta_y;
	static double previous_mouse_x;
	static double previous_mouse_y;

	static bool first_mouse_event;
};

