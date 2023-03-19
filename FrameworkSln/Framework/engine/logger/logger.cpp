#include "logger.h"

std::shared_ptr<spdlog::logger> Logger::engineLogger;
std::shared_ptr<spdlog::logger> Logger::renderLogger;
std::shared_ptr<spdlog::logger> Logger::shaderLogger;

Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::Init()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");

	engineLogger = spdlog::stdout_color_mt("ENGINE");
	engineLogger->set_level(spdlog::level::trace);

	renderLogger = spdlog::stderr_color_mt("RENDER");
	renderLogger->set_level(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger> Logger::GetEngineLogger()
{
	return engineLogger;
}

std::shared_ptr<spdlog::logger> Logger::GetRenderLogger()
{
	return renderLogger;
}

std::shared_ptr<spdlog::logger> Logger::GetShaderLogger()
{
	return shaderLogger;
}
