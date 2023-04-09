#include <iostream>

#include "src/world.h"
#include "Test.h"

int main(int argc, char** argv) {
	window_properties* wp = new window_properties{ "OpenGL Framework", 1280, 720 };

	Engine::Init(wp);
	World* test = new Test();

	test->Init();
	test->Run();

	Engine::Exit();

	return 0;
}