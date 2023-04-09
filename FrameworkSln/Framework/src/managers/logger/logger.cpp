#include "logger.h"

void Logger::Init()
{	
	console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	console_sink->set_pattern("%^[%T] %n: %v%$");

	sinks = { console_sink };

	core_logger = std::make_shared < spdlog::logger>(FRAMEWORK_CORE_LOGGER_NAME, sinks.begin(), sinks.end());
	core_logger->set_level(spdlog::level::trace);
	core_logger->flush_on(spdlog::level::trace);
	spdlog::register_logger(core_logger);

	engine_logger = std::make_shared < spdlog::logger>(FRAMEWORK_ENGINE_LOGGER_NAME, sinks.begin(), sinks.end());
	engine_logger->set_level(spdlog::level::trace);
	engine_logger->flush_on(spdlog::level::trace);
	spdlog::register_logger(engine_logger);

	shader_logger = std::make_shared < spdlog::logger>(FRAMEWORK_SHADER_LOGGER_NAME, sinks.begin(), sinks.end());
	shader_logger->set_level(spdlog::level::trace);
	shader_logger->flush_on(spdlog::level::trace);
	spdlog::register_logger(shader_logger);

	render_logger = std::make_shared < spdlog::logger>(FRAMEWORK_RENDER_LOGGER_NAME, sinks.begin(), sinks.end());
	render_logger->set_level(spdlog::level::trace);
	render_logger->flush_on(spdlog::level::trace);
	spdlog::register_logger(render_logger);

	texture_logger = std::make_shared < spdlog::logger>(FRAMEWORK_TEXTURE_LOGGER_NAME, sinks.begin(), sinks.end());
	texture_logger->set_level(spdlog::level::trace);
	texture_logger->flush_on(spdlog::level::trace);
	spdlog::register_logger(texture_logger);
}

void Logger::Shutdown()
{
	spdlog::shutdown();
}
