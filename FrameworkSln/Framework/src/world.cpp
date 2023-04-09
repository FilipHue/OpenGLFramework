#include "world.h"

World::World()
{
	p_window = Engine::GetWindow();
	d_elapsed_time = d_previous_time = d_delta_time = 0.0f;
}

void World::Run()
{
	if (p_window == nullptr) {
		return;
	}

	while (!p_window->ShouldClose()) {
		LoopUpdate();
	}
}

void World::Exit()
{
	glfwSetWindowShouldClose(p_window->GetNativeWindow(), 1);
}

double World::GetDeltaTime()
{
	return d_delta_time;
}

void World::ComputeDeltaTime()
{
	d_elapsed_time = Engine::GetElapsedTime();
	d_delta_time = d_elapsed_time - d_previous_time;
	d_previous_time = d_elapsed_time;
}

void World::LoopUpdate()
{
	ComputeDeltaTime();

	p_window->PollEvents();
	p_window->ContinousEvents(d_delta_time);

	StartFrame();
	Update(d_delta_time);
	EndFrame();

	p_window->SwapBuffers();
}
