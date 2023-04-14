#include "window.h"

std::list<InputController*> Window::input_controllers;
bool Window::key_states[GLFW_KEY_LAST] = {};
bool Window::continous_key_events[GLFW_KEY_LAST] = {};
int Window::key_mods = 0;

double Window::mouse_x = 0;
double Window::mouse_y = 0;
double Window::mouse_delta_x = 0;
double Window::mouse_delta_y = 0;
double Window::previous_mouse_x = 0;
double Window::previous_mouse_y = 0;

bool Window::first_mouse_event = false;

void Window::Init(window_properties* wp)
{
	p_properties = wp;
	resolution.x = wp->width;
	resolution.y = wp->height;
	project_dir = wp->project_directory;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	SetWindowHints();

	p_native_monitor = glfwGetPrimaryMonitor();
	p_video_mode = glfwGetVideoMode(p_native_monitor);
	p_native_window = glfwCreateWindow(wp->width, wp->height, wp->title, NULL, NULL);
	if (p_native_window == nullptr) {
		CORE_ERROR("Window not initialized");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(p_native_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		CORE_ERROR("GLAD not initialized");
	}

	CenterWindow();
	CenterCursor();
	DisableCursor();
	SetWindowCallbacks();

	CORE_INFO("Window intialized");
}

void Window::Shutdown()
{
	glfwDestroyWindow(p_native_window);
	CORE_INFO("Window context destroyed");
}

void Window::PollEvents()
{
	glfwPollEvents();
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(p_native_window);
}

int Window::ShouldClose()
{
	b_should_close = glfwWindowShouldClose(p_native_window);

	return b_should_close;
}

GLFWwindow* Window::GetNativeWindow()
{
	return p_native_window;
}


void Window::KeyCallbacks(int key, int scancode, int action, int mods)
{
	key_mods = mods;
	if (key >= 0 && key <= GLFW_KEY_LAST) {
		key_states[key] = (action == GLFW_PRESS);
		continous_key_events[key] = (action == GLFW_REPEAT);
	}

	for (auto ic : input_controllers) {
		action ? ic->OnKeyPress(key, mods) : ic->OnKeyRelease(key, mods);
	}
}

void Window::MouseButtonCallbacks(int button, int action, int mods)
{
	key_mods = mods;
	for (auto ic : input_controllers) {
		action ? ic->OnMouseButtonPress(mouse_x, mouse_y, button, mods) : ic->OnMouseButttonRelease(mouse_x, mouse_y, button, mods);
	}
}

void Window::MouseMoveCallbacks(double x_pos, double y_pos)
{	
	if (first_mouse_event) {
		mouse_delta_x = x_pos - previous_mouse_x;
		mouse_delta_y = y_pos - previous_mouse_y;
	}
	else {
		first_mouse_event = true;
	}

	previous_mouse_x = mouse_x;
	previous_mouse_y = mouse_y;

	mouse_x = x_pos;
	mouse_y = y_pos;

	for (auto ic : input_controllers) {
		ic->OnMouseMove(x_pos, y_pos, mouse_delta_x, mouse_delta_y);
	}
}

void Window::MouseScrollCallbacks(double x_offset, double y_offset)
{
	for (auto ic : input_controllers) {
		ic->OnMouseScroll(x_offset, y_offset);
	}
}

void Window::ContinousEvents(double delta_time)
{
	for (auto ic : input_controllers) {
		ic->OnInputUpdate(delta_time, key_mods);
	}
}

void Window::SetWindowHints()
{
	glfwWindowHint(GLFW_RESIZABLE, p_properties->resiable);
	glfwWindowHint(GLFW_VISIBLE, p_properties->visible);
	glfwWindowHint(GLFW_DECORATED, p_properties->decorated);
	glfwWindowHint(GLFW_FOCUSED, p_properties->focused);
	glfwWindowHint(GLFW_AUTO_ICONIFY, p_properties->auto_iconify);
	glfwWindowHint(GLFW_FLOATING, p_properties->floating);
	glfwWindowHint(GLFW_MAXIMIZED, p_properties->maximized);
	glfwWindowHint(GLFW_CENTER_CURSOR, p_properties->center_cursor);

	CORE_INFO("Window hints set");
}

void Window::SetWindowCallbacks()
{
	glfwSetKeyCallback(p_native_window, WindowCallbacks::KeyCallback);
	glfwSetCursorPosCallback(p_native_window, WindowCallbacks::MouseMove);
	glfwSetMouseButtonCallback(p_native_window, WindowCallbacks::MousePress);
	glfwSetScrollCallback(p_native_window, WindowCallbacks::MouseScroll);
}

void Window::SetCursor(int x_pos, int y_pos)
{
	glfwSetCursorPos(p_native_window, x_pos, y_pos);
}

void Window::CenterCursor()
{
	SetCursor(p_properties->width / 2, p_properties->height / 2);
	mouse_x = p_properties->width / 2;
	mouse_y = p_properties->height / 2;
}

void Window::ShowCursor()
{
	glfwSetInputMode(p_native_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void Window::HideCursor()
{
	glfwSetInputMode(p_native_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

void Window::DisableCursor()
{
	glfwSetInputMode(p_native_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Window::SetWindow(int x_pos, int y_pos)
{
	glfwSetWindowPos(p_native_window, x_pos, y_pos);
}

void Window::CenterWindow()
{
	SetWindow(p_video_mode->width / 2 - p_properties->width / 2, p_video_mode->height / 2 - p_properties->height / 2);
}

bool Window::GetContinousPress(int key)
{
	return (continous_key_events[key] || key_states[key]);;
}

void Window::SubscribeToEvents(InputController* ic)
{
	input_controllers.push_back(ic);
}

void Window::UnsubscribeFromEvents(InputController* ic)
{
	input_controllers.remove(ic);
}
