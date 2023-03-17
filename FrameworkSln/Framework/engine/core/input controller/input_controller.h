#pragma once

#include "../window/window.h"

class InputController
{
	friend class Window;

public:
	/**
	  * Constructor for InputController class
	  * Connects the window with the input controller
	  */
	InputController();
	~InputController();

protected:
	Window* window;

protected:
	/**
	  * Method is called every frame before the Update method
	  * Used for frame independent interactions
	  * @param deltaTime The time between two consecutives frames
	  * @param mods Holds the codes of special keys (or combinations of them): ALT, SHIFT, CTRL etc.
	  */
	virtual void OnInputUpdate(double deltaTime, int mods) = 0;
	/**
	  * Method is called before the Update method when a key press event is registered
	  * @param key The key that was pressed
	  * @param mods Holds the codes of special keys (or combinations of them): ALT, SHIFT, CTRL etc.
	  */
	virtual void OnKeyPress(int key, int mods) = 0;
	/**
	  * Method is called before the Update method when a key release event is registered
	  * @param key The key that was pressed
	  * @param mods Holds the codes of special keys (or combinations of them): ALT, SHIFT, CTRL etc.
	  */
	virtual void OnKeyRelease(int key, int mods) = 0;

	/**
	  * Method is called before the Update method when a mouse move event is registered
	  * @param mouseX X coordinate in pixels of the mouse position relative to the top-left corner ([0, 0])
	  * @param mouseY Y coordinate in pixels of the mouse position relative to the top-left corner
	  * @param deltaX The distance on the OX axis that the mouse moved between the current frame and the last frame
	  * @param deltaY The distance on the OX axis that the mouse moved between the current frame and the last frame
	  */
	virtual void OnMouseMove(double mouseX, double mouseY, double deltaX, double deltaY) = 0;
	/**
	  * Method is called before the Update method when a mouse button press event is registered
	  * @param mouseX X coordinate in pixels of the mouse position relative to the top-left corner ([0, 0])
	  * @param mouseY Y coordinate in pixels of the mouse position relative to the top-left corner
	  * @param button The button that was pressed
	  * @param mods Holds the codes of special keys (or combinations of them): ALT, SHIFT, CTRL etc.
	  */
	virtual void OnMouseButtonPress(double mouseX, double mouseY, int button, int mods) = 0;
	/**
	  * Method is called before the Update method when a mouse button release event is registered
	  * @param mouseX X coordinate in pixels of the mouse position relative to the top-left corner ([0, 0])
	  * @param mouseY Y coordinate in pixels of the mouse position relative to the top-left corner
	  * @param button The button that was pressed
	  * @param mods Holds the codes of special keys (or combinations of them): ALT, SHIFT, CTRL etc.
	  */
	virtual void OnMouseButttonRelease(double mouseX, double mouseY, int button, int mods) = 0;
	/**
	  * Method is called before the Update method when a mouse scroll event is registered
	  * @param mouseX X coordinate in pixels of the mouse position relative to the top-left corner ([0, 0])
	  * @param mouseY Y coordinate in pixels of the mouse position relative to the top-left corner
	  * @param scrollOffsetX The scroll offset on the OX axis
	  * @param scrollOffsetY The scroll offset on the OY axis
	  */
	virtual void OnMouseScroll(double mouseX, double mouseY, double scrollOffsetX, double scrollOffsetY) = 0;

	/**
	  * Method is called before the Update method when a window resize event is registered during the last frame
	  * @param width The new width of the window
	  * @param height The new height of the window
	  */
	virtual void OnWindowResize(int width, int height) = 0;
};
