#include "world.h"

World::World()
{
	window = Engine::GetWindow();
	deltaTime = previousTime = elapsedTime = 0.0f;
	ENGINE_INFO("Created world");
}

World::~World()
{
}

void World::Run()
{
	if (!window) {
		return;
	}

	while (!window->ShouldClose()) {
		LoopUpdate();
	}
}

void World::Exit()
{
	ENGINE_INFO("Exiting...");
;	glfwSetWindowShouldClose(window->nativeWindow, 1);
}

double World::GetDeltaTime()
{
	return deltaTime;
}

void World::ComputeDeltaTime()
{
	elapsedTime = Engine::GetElapsedTime();
	deltaTime = elapsedTime - previousTime;
	previousTime = elapsedTime;
}

void World::LoopUpdate()
{
	ComputeDeltaTime();

	window->PollEvents();
	window->ContinousEvents(GetDeltaTime());

	StartFrame();
	Update(deltaTime);
	EndFrame();

	window->SwapBuffers();
}
