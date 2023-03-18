#pragma once

#include "core.h"
#include "window_properties.h"
#include "window_callbacks.h"
#include "../input controller/input_controller.h"

class Window
{
	friend class WindowCallbacks;
	friend class InputController;

public:
	/**
	  * Constructor for Window class
	  * Sets the openGL version
	  * Gets primary monitor
	  * Creates the window object and sets it as current context
	  * Initialize GLAD, sets callbacks, sets cursor properties
	  * @param wp Strcture of type WindowProperties containing window properties
	  */
	Window(WindowProperties wp);
	/** 
	  * Deconstructor for Window class
	  * Destroys the window object created with glfw
	  */
	~Window();

	/**
	  * Function called for keyboard input event
	  * @param key The key pressed
	  * @param scancode The scancode of the key
	  * @param action Stores the action of the key, can be of type GL_PRESS, GL_REPEAT or GL_RELEASE
	  * @param mods Stores the combination of special key presses (SHIFT, ALT, TAB etc.)
	  */
	void KeyCallback(int key, int scancode, int action, int mods);
	/**
	  * Function called for mouse button presses event
	  * @param button The mouse button pressed
	  * @param action Stores the action of the mouse button, can be of type GL_PRESS or GL_RELEASE
	  * @param mods Stores the combination of special keys (SHIFT, ALT, TAB etc.)
	  */
	void MouseButtonCallbacks(int button, int action, int mods);
	/**
	  * Function called for mouse move event
	  * @param posX Position on the OX axis of the mouse cursor
	  * @param posY Position on the OY axis of the mouse cursor
	  */
	void MouseMoveCallback(double posX, double posY);
	/**
	  * Function called for mouse scroll event
	  * @param scrollOffsetX Offset on the OX axis
	  * @param scrollOffsetY Offset on the OY axis
	  */
	void MouseScrollCallback(double scrollOffsetX, double scrollOffsetY);
	/**
	  * Checks for events every frame (keyboard, mouse etc.)
	  * @param deltaTime The time between two consecutives frames, for frame independent calculations
	  */
	void ContinousEvents(double deltaTime);

	/**
	  * Sets the position of the mouse cursor
	  * @param posX Position on the OX axis where we want the cursor to be
	  * @param posY Position on the OY axis where we want the cursor to be
	  */
	void SetCursor(int posX, int posY);
	/**
	  * Sets the cursor in the middle of the screen
	  */
	void CenterCursor();
	/**
	  * Hides the cursor 
	  */
	void HideCursor();
	/**
	  * Shows the cursor 
	  */
	void ShowCursor();
	/**
	  * Disables the cursor
	  * It is used whene we need continous/infinte mouse movement (ex: camera input)
	  * Check - https://www.glfw.org/docs/3.3/input_guide.html#cursor_mode - for more information
	  */
	void DisableCursor();

	/**
	  * Sets the window position inside the screen area (monitor)
	  * @param posX Position on the OX axis of the window
	  * @param poxY Position on the OY axis of the window
	  */
	void SetWindow(int posX, int posY);
	/**
	  * Sets the window position to be in the center of the screen
	  */
	void CenterWindow();

	/**
	  * Checks if the window should close 
	  */
	int ShouldClose();
	/**
	  * Swaps the buffers
	  */
	void SwapBuffers();
	/**
	  * Polls for events 
	  */
	void PollEvents();

	/**
	  * Checks if a key is either being pressed or has just been pressed
	  * @param key The key which we want to check
	  */
	bool GetKeyState(int key);

public:
	GLFWwindow* nativeWindow;
	GLFWmonitor* nativeMonitor;

	glm::ivec2 resolution;

private:
	/**
	  * Sets the callback functions 
	  */
	void SetCallbacks();
	/**
	  * Binds an input controller to the window
	  * Necessar for callbacks - see window_callbacks.h and input_controller.h
	  */
	void SubscribeToEvents(InputController* ic);
	/**
	  * Unbinds an input controller from the window
	  * Necessar for callbacks - see window_callbacks.h and input_controller.h
	  */
	void UnsubscribeFromEvents(InputController* ic);

private:
	bool keyStates[GLFW_KEY_LAST] = {};
	bool continousKeyEvents[GLFW_KEY_LAST] = {};
	bool mouseMoveEvent;

	double mouseX;
	double mouseY;
	double previousMouseX;
	double previousMouseY;
	double deltaMouseX;
	double deltaMouseY;
	double scrollOffsetX;
	double scrollOffsetY;

	int keyMods;

	std::list<InputController*> inputControllers;
};

