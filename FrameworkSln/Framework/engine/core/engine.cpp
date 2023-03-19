#include "engine.h"

Window* Engine::gameWindow = nullptr;

Window* Engine::Init(WindowProperties wp)
{
    if (!glfwInit()) {
        exit(0);
    }

    gameWindow = new Window(wp);

    ENGINE_INFO("Initalized engine");

    return gameWindow;
}

Window* Engine::GetWindow() {
    return gameWindow;
}

double Engine::GetElapsedTime()
{
    return glfwGetTime();
}

void Engine::Exit()
{
    ENGINE_INFO("Stoping engine");
    glfwTerminate();
}
