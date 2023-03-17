#pragma once

#include "core/engine.h"
#include "core/input controller/input_controller.h"

class World : public InputController
{
public:
	/**
	  * Constructor for World class
	  * Gets the window from the Input Controller
	  */
	World();
	~World();

	/**
	  * Method is called once before any other method
	  * Can be used to initialize resources for the scene
	  */
	virtual void Init() = 0;
	/**
	  * Method is called every frame, at the start of the frame, before the Update method
	  */
	virtual void StartFrame() = 0;
	/**
	  * Method is called every frame
	  * This is the main game loop
	  * @param deltaTime The time between 2 consecutives frmaes, used for frame independent interactions
	  */
	virtual void Update(double deltaTime) = 0;
	/**
	  * The method is called every frame, at the end of the frame, after the Update method 
	  */
	virtual void EndFrame() = 0;

	/**
	  * Method starts the game loop, calling LoopUpdate method while the window is active
	  */
	void Run();
	/**
	  * Method ends the game loop, calling method Exit from Engine class 
	  */
	void Exit();

	/**
	  * Returns the time between two consecutive frames (the current frame and the last frame)
	  */
	double GetDeltaTime();

private:
	/**
	  * Calculates the time between two consecutive frames 
	  */
	void ComputeDeltaTime();
	/**
	  * Calculates the new delta time
	  * Poll for events
	  * Check for continous type events
	  * Calls StartFrame, Update and EndFrame methods
	  * Swaps buffers
	  */
	void LoopUpdate();

private:
	double elapsedTime;
	double previousTime;
	double deltaTime;
};
