#include "engine.h"

Window* Engine::p_window = nullptr;
Logger* Engine::p_logger;

void Engine::Init(window_properties* wp)
{
    p_logger = new Logger();
    p_logger->Init();

    if (!glfwInit()) {
        ENGINE_ERROR("GLFW library initialization was unsuccesful");
        exit(0);
    }

    p_window = new Window();
    p_window->Init(wp);

    ENGINE_INFO("Engine succesfully initialized");
}

void Engine::Exit()
{
    glfwTerminate();
    ENGINE_INFO("Shuting down engine...");
}

Window* Engine::GetWindow()
{
    return p_window;
}

double Engine::GetElapsedTime()
{
    return glfwGetTime();
}
