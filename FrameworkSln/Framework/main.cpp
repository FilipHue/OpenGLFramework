#include <core.h>

#include "engine/core/window/window.h"
#include "engine/core/window/window_properties.h"

#include "engine/core/engine.h"
#include "engine/world.h"

#include "Test.h"



int main(int argc, char** argv) {
	std::string directoryName;

	directoryName = argv[0];
	directoryName.erase(directoryName.begin() + directoryName.find("bin"), directoryName.end());

	WindowProperties wp = WindowProperties{1280, 720, true, "Test Window", directoryName};

	Window* window = Engine::Init(wp);

	World* test = new Test();

	test->Init();
	test->Run();
	
	Engine::Exit();

	return 0;
}