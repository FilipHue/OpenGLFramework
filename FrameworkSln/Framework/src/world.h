#pragma once

#include "engine/engine.h"
#include "engine/core/input_controller/input_controller.h"

class World : public InputController
{
public:
	World();

	virtual void Init() = 0;
	virtual void StartFrame() = 0;
	virtual void Update(double delta_time) = 0;
	virtual void EndFrame() = 0;

	/**
	 * @brief	Calls the loop update method while the window is active
	*/
	void Run();
	void Exit();

	double GetDeltaTime();

private:
	void ComputeDeltaTime();
	/**
	 * @brief	Method for running the framework
	 * @brief	Calls the necesary functions in order
	*/
	void LoopUpdate();

private:
	double d_delta_time;
	double d_elapsed_time;
	double d_previous_time;

	Window* p_window;
};

