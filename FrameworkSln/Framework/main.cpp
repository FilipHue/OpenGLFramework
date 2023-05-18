#include <iostream>

#include "src/world.h"
#include "demos.h"
#include "Demo.h"

int main(int argc, char** argv) {
	std::string project_directory;
	
	project_directory = argv[0];
	project_directory = project_directory.substr(0, project_directory.find("\\_exec"));	

	window_properties* wp = new window_properties{ "OpenGL Framework", project_directory, 1280, 720};

	Engine::Init(wp);
	World* test = new DemoBlending();

	test->Init();
	test->Run();

	Engine::Exit();

	return 0;
}
