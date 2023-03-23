#pragma once

/**
  * The strcuture contains some usefull window properties
  * More can be added if needed
  */

typedef struct win_prop WindowProperties;
struct win_prop {
	win_prop(
		int width,
		int height,
		bool vsync,
		const char* windowTitle,
		std::string directoryName,
		glm::ivec2 position = glm::ivec2(0),
		glm::ivec2 cursorPosition = glm::ivec2(0)
	) : width(width), height(height), vsync(vsync), windowTitle(windowTitle), directoryName(directoryName), position(position), cursorPosition(cursorPosition) {}

	int width;
	int height;

	bool vsync;

	const char* windowTitle;
	std::string directoryName;

	glm::ivec2 position;
	glm::ivec2 cursorPosition;
};
