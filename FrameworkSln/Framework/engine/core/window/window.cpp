#include "window.h"

Window::Window(WindowProperties wp)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	nativeMonitor = glfwGetPrimaryMonitor();
	nativeWindow = glfwCreateWindow(wp.width, wp.height, wp.windowTitle, NULL, NULL);
	resolution = glm::ivec2(wp.width, wp.height);

	if (nativeWindow == NULL) {
		std::cout << "Failed to create GLFW window!" << std::endl;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(nativeWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

	SetCallbacks();

	CenterWindow();

	DisableCursor();
	CenterCursor();

	deltaMouseX = deltaMouseY = 0;
	mouseMoveEvent = false;
}

Window::~Window()
{
	glfwDestroyWindow(nativeWindow);
}

void Window::KeyCallback(int key, int scancode, int action, int mods)
{
	keyMods = mods;
	if (key >= 0 && key <= GLFW_KEY_LAST) {
		keyStates[key] = (action == GLFW_PRESS);
		continousKeyEvents[key] = (action == GLFW_REPEAT);
	}

	for (auto inputController : inputControllers) {
		keyStates[key] ? inputController->OnKeyPress(key, mods) : inputController->OnKeyRelease(key, mods);
	}
}

void Window::MouseButtonCallbacks(int button, int action, int mods)
{
	keyMods = mods;
	for (auto inputController : inputControllers) {
		action ? inputController->OnMouseButtonPress(mouseX, mouseY, button, mods) : inputController->OnMouseButttonRelease(mouseX, mouseY, button, mods);
	}
}

void Window::MouseMoveCallback(double posX, double posY)
{	
	if (mouseMoveEvent) {
		deltaMouseX = posX - previousMouseX;
		deltaMouseY = posY - previousMouseY;
	}
	else {
		mouseMoveEvent = true;
		deltaMouseX = 0;
		deltaMouseY = 0;
	}

	previousMouseX = mouseX;
	previousMouseY = mouseY;

	mouseX = posX;
	mouseY = posY;

	for (auto inputController : inputControllers) {
		inputController->OnMouseMove(mouseX, mouseY, deltaMouseX, deltaMouseY);
	}
}

void Window::MouseScrollCallback(double offsetX, double offsetY)
{
	for (auto inputController : inputControllers) {
		inputController->OnMouseScroll(mouseX, mouseY, offsetX, offsetY);
	}
}

void Window::ContinousEvents(double deltaTime)
{
	for (auto inputController : inputControllers) {
		inputController->OnInputUpdate(deltaTime, keyMods);
	}
}

void Window::SetWindow(int posX, int posY)
{
	glfwSetWindowPos(nativeWindow, posX, posY);
}

void Window::CenterWindow()
{
	auto monitorSize = glm::ivec2(glfwGetVideoMode(nativeMonitor)->width, glfwGetVideoMode(nativeMonitor)->height);
	SetWindow((monitorSize.x - resolution.x) / 2, (monitorSize.y - resolution.y) / 2);
}

int Window::ShouldClose()
{
	return glfwWindowShouldClose(nativeWindow);
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(nativeWindow);
}

void Window::PollEvents()
{
	glfwPollEvents();
}

bool Window::GetKeyState(int key)
{
	return (continousKeyEvents[key] || keyStates[key]);
}

void Window::SetCursor(int posX, int posY)
{
	mouseX = posX;
	mouseY = posY;
	previousMouseX = mouseX;
	previousMouseY = mouseY;
	glfwSetCursorPos(nativeWindow, posX, posY);
}

void Window::CenterCursor()
{
	int posX, posY;

	posX = resolution.x / 2;
	posY = resolution.y / 2;

	SetCursor(posX, posY);
}

void Window::HideCursor()
{
	glfwSetInputMode(nativeWindow, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

void Window::ShowCursor()
{
	glfwSetInputMode(nativeWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void Window::DisableCursor()
{
	glfwSetInputMode(nativeWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Window::SetCallbacks()
{
	glfwSetWindowCloseCallback(nativeWindow, WindowCallbacks::OnClose);
	glfwSetWindowSizeCallback(nativeWindow, WindowCallbacks::OnResize);
	glfwSetKeyCallback(nativeWindow, WindowCallbacks::KeyCallbacks);
	glfwSetMouseButtonCallback(nativeWindow, WindowCallbacks::MouseClick);
	glfwSetCursorPosCallback(nativeWindow, WindowCallbacks::CursorMove);
	glfwSetScrollCallback(nativeWindow, WindowCallbacks::ScrollMove);
}

void Window::SubscribeToEvents(InputController* ic)
{
	inputControllers.push_back(ic);
}

void Window::UnsubscribeFromEvents(InputController* ic)
{
	inputControllers.remove(ic);
}
