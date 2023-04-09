#pragma once

#include "../window/window.h"

class InputController
{
	friend class Window;

public:
	/**
	 * @brief Method for connecting the input controller to a component
	*/
	InputController();
	~InputController();

	/**
	 * @brief Method for toggling the state of the input controller (active or not)
	*/
	void ToogleEvents();
	/**
	 * @brief				Method for checking the state of the input controller
	 * @return				1 if it's active or 0 otheriwse
	*/
	bool IsActive();

protected:
	/**
	 * @brief				Method for handling continous events (like key presses)
	 * @param delta_time	The time between the current frame and last frame
	 * @param mods			The code of combination presses with special keys (L_SHIFT, L_ALT, L_CTRL, R_SHIFT, R_ALT, R_CTRL)
	*/
	virtual void OnInputUpdate(double delta_time, int mods) = 0;

	/**
	 * @brief				Method for handling key presses
	 * @param key			The code of the pressed key
	 * @param mods			The code of combination presses with special keys (L_SHIFT, L_ALT, L_CTRL, R_SHIFT, R_ALT, R_CTRL)
	*/
	virtual void OnKeyPress(int key, int mods) = 0;
	/**
	 * @brief				Method for handling key releases
	 * @param key			The code of the released key
	 * @param mods			The code of combination presses with special keys (L_SHIFT, L_ALT, L_CTRL, R_SHIFT, R_ALT, R_CTRL)
	*/
	virtual void OnKeyRelease(int key, int mods) = 0;

	/**
	 * @brief				Method for handling mouse movement
	 * @param x_pos			The X position of the mouse at the time of the movement
	 * @param y_pos			The Y position of the mouse at the time of the movement
	 * @param delta_x		The distance between the last X position of the mouse and x_pos
	 * @param delta_y		The distance between the last Y position of the mouse and y_pos
	*/
	virtual void OnMouseMove(double x_pos, double y_pos, double delta_x, double delta_y) = 0;
	/**
	 * @brief				Method for handling mouse button presses
	 * @param x_pos			The X position of the mouse at the time of the button press
	 * @param y_pos			The Y position of the mouse at the time of the button press
	 * @param button		The code of the button pressed
	 * @param mods			The code of combination presses with special keys (L_SHIFT, L_ALT, L_CTRL, R_SHIFT, R_ALT, R_CTRL)
	*/
	virtual void OnMouseButtonPress(double x_pos, double y_pos, int button, int mods) = 0;
	/**
	 * @brief				Method for handling mouse button releases
	 * @param x_pos			The X position of the mouse at the time of the button release
	 * @param y_pos			The Y position of the mouse at the time of the button release
	 * @param button		The code of the button released
	 * @param mods			The code of combination presses with special keys (L_SHIFT, L_ALT, L_CTRL, R_SHIFT, R_ALT, R_CTRL)
	*/
	virtual void OnMouseButttonRelease(double x_pos, double y_pos, int button, int mods) = 0;
	/**
	 * @brief				Method for handling mouse scroll
	 * @param x_offset		The X offset of the scroll
	 * @param y_offset		The Y offset of the scroll
	*/
	virtual void OnMouseScroll(double x_offset, double y_offset) = 0;

private:
	bool b_is_active;
};

