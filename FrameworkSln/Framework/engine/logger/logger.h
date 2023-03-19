#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <memory>

class Logger
{
public:
	Logger();
	~Logger();

	void Init();

	static std::shared_ptr<spdlog::logger> GetEngineLogger();
	static std::shared_ptr<spdlog::logger> GetRenderLogger();
	static std::shared_ptr<spdlog::logger> GetShaderLogger();

private:
	static std::shared_ptr<spdlog::logger> engineLogger;
	static std::shared_ptr<spdlog::logger> renderLogger;
	static std::shared_ptr<spdlog::logger> shaderLogger;
};

#define ENGINE_TRACE(...)	Logger::GetEngineLogger()->trace(__VA_ARGS__);
#define ENGINE_INFO(...)	Logger::GetEngineLogger()->info(__VA_ARGS__);
#define ENGINE_WARN(...)	Logger::GetEngineLogger()->warn(__VA_ARGS__);
#define ENGINE_ERROR(...)	Logger::GetEngineLogger()->error(__VA_ARGS__);

#define RENDER_TRACE(...)	Logger::GetRenderLogger()->trace(__VA_ARGS__);
#define RENDER_INFO(...)	Logger::GetRenderLogger()->info(__VA_ARGS__);
#define RENDER_WARN(...)	Logger::GetRenderLogger()->warn(__VA_ARGS__);
#define RENDER_ERROR(...)	Logger::GetRenderLogger()->error(__VA_ARGS__);

#define SHADER_TRACE(...)	Logger::GetShaderLogger()->trace(__VA_ARGS__);
#define SHADER_INFO(...)	Logger::GetShaderLogger()->info(__VA_ARGS__);
#define SHADER_WARN(...)	Logger::GetShaderLogger()->warn(__VA_ARGS__);
#define SHADER_ERROR(...)	Logger::GetShaderLogger()->error(__VA_ARGS__);
