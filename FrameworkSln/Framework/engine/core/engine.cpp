#include "engine.h"

Window* Engine::gameWindow = nullptr;

Window* Engine::Init(WindowProperties wp)
{
    if (!glfwInit()) {
        exit(0);
    }

    gameWindow = new Window(wp);

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
    glfwTerminate();
}
