#pragma once

#include "../managers/logger/logger.h"
#include "core/window/window.h"
#include "core/window/window_properties.h"

class Engine
{
public:
	/**
	 * @brief		Safety measure in case we accidentaly create an Engine object
	*/
	Engine() = delete;

	/**
	 * @brief		Method for initializing the glfw library, window and logger
	 * @param wp	Window properties
	*/
	static void Init(window_properties* wp);
	/**
	 * @brief		Method for terminating the glfw library
	*/
	static void Exit();
	static Window* GetWindow();
	static double GetElapsedTime();

private:
	static Window* p_window;
	static Logger* p_logger;
};

