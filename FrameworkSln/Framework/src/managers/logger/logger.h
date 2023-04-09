#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <memory>
#include <vector>

#include "log.h"

class Logger
{
public:
	void Init();
	void Shutdown();

private:
	std::shared_ptr<spdlog::logger> core_logger;
	std::shared_ptr<spdlog::logger> engine_logger;
	std::shared_ptr<spdlog::logger> shader_logger;
	std::shared_ptr<spdlog::logger> render_logger;
	std::shared_ptr<spdlog::logger> texture_logger;

	std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> console_sink;

	std::vector<spdlog::sink_ptr> sinks;
};

