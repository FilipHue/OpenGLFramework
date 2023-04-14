#pragma once

#include <string>

/**
 * @brief Structure for keeping window properties
 * @brief See https://www.glfw.org/docs/latest/window_guide.html#window_hints for more information
*/
typedef struct window_properties window_properties;
struct window_properties {
	const char* title;
	std::string project_directory;

	unsigned int width;
	unsigned int height;
	double aspect_ration;

	bool vsync;
	bool resiable;
	bool visible;
	bool decorated;
	bool focused;
	bool auto_iconify;
	bool floating;
	bool maximized;
	bool center_cursor;

	int refresh_rate;

	window_properties(
		const char* title,
		std::string project_directory,

		unsigned int width,
		unsigned int height,
		double aspect_ration = 0.0f,

		bool vsync = GLFW_FALSE,
		bool resizable = GLFW_FALSE,
		bool visible = GLFW_TRUE,
		bool decorated = GLFW_TRUE,
		bool focused = GLFW_TRUE,
		bool auto_iconify = GLFW_TRUE,
		bool floating = GLFW_TRUE,
		bool maximized = GLFW_FALSE,
		bool center_cursor = GLFW_TRUE,

		int refresh_rate = 60
	) : title(title), project_directory(project_directory),
		width(width), height(height), aspect_ration((double)width / height),
		vsync(vsync), resiable(resizable), visible(visible),
		decorated(decorated), focused(focused), auto_iconify(auto_iconify),
		floating(floating), maximized(maximized), center_cursor(center_cursor),
		refresh_rate(refresh_rate) {}
};
