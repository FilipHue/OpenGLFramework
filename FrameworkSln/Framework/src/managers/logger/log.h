#pragma once

#include "spdlog/spdlog.h"

#define FRAMEWORK_CORE_LOGGER_NAME "CORE"
#define FRAMEWORK_ENGINE_LOGGER_NAME "ENGINE"
#define FRAMEWORK_SHADER_LOGGER_NAME "SHADER"
#define FRAMEWORK_RENDER_LOGGER_NAME "RENDER"
#define FRAMEWORK_TEXTURE_LOGGER_NAME "TEXTURE"

#define CORE_TRACE(...) if (spdlog::get(FRAMEWORK_CORE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_CORE_LOGGER_NAME)->trace(__VA_ARGS__);}
#define CORE_DEBUG(...) if (spdlog::get(FRAMEWORK_CORE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_CORE_LOGGER_NAME)->debug(__VA_ARGS__);}
#define CORE_INFO(...) if (spdlog::get(FRAMEWORK_CORE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_CORE_LOGGER_NAME)->info(__VA_ARGS__);}
#define CORE_WARN(...) if (spdlog::get(FRAMEWORK_CORE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_CORE_LOGGER_NAME)->warn(__VA_ARGS__);}
#define CORE_ERROR(...) if (spdlog::get(FRAMEWORK_CORE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_CORE_LOGGER_NAME)->error(__VA_ARGS__);}
#define CORE_CRITICAL(...) if (spdlog::get(FRAMEWORK_CORE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_CORE_LOGGER_NAME)->critical(__VA_ARGS__);}

#define ENGINE_TRACE(...) if (spdlog::get(FRAMEWORK_ENGINE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_ENGINE_LOGGER_NAME)->trace(__VA_ARGS__);}
#define ENGINE_DEBUG(...) if (spdlog::get(FRAMEWORK_ENGINE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_ENGINE_LOGGER_NAME)->debug(__VA_ARGS__);}
#define ENGINE_INFO(...) if (spdlog::get(FRAMEWORK_ENGINE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_ENGINE_LOGGER_NAME)->info(__VA_ARGS__);}
#define ENGINE_WARN(...) if (spdlog::get(FRAMEWORK_ENGINE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_ENGINE_LOGGER_NAME)->warn(__VA_ARGS__);}
#define ENGINE_ERROR(...) if (spdlog::get(FRAMEWORK_ENGINE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_ENGINE_LOGGER_NAME)->error(__VA_ARGS__);}
#define ENGINE_CRITICAL(...) if (spdlog::get(FRAMEWORK_ENGINE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_ENGINE_LOGGER_NAME)->critical(__VA_ARGS__);}

#define SHADER_TRACE(...) if (spdlog::get(FRAMEWORK_SHADER_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_SHADER_LOGGER_NAME)->trace(__VA_ARGS__);}
#define SHADER_DEBUG(...) if (spdlog::get(FRAMEWORK_SHADER_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_SHADER_LOGGER_NAME)->debug(__VA_ARGS__);}
#define SHADER_INFO(...) if (spdlog::get(FRAMEWORK_SHADER_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_SHADER_LOGGER_NAME)->info(__VA_ARGS__);}
#define SHADER_WARN(...) if (spdlog::get(FRAMEWORK_SHADER_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_SHADER_LOGGER_NAME)->warn(__VA_ARGS__);}
#define SHADER_ERROR(...) if (spdlog::get(FRAMEWORK_SHADER_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_SHADER_LOGGER_NAME)->error(__VA_ARGS__);}
#define SHADER_CRITICAL(...) if (spdlog::get(FRAMEWORK_SHADER_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_SHADER_LOGGER_NAME)->critical(__VA_ARGS__);}

#define RENDER_TRACE(...) if (spdlog::get(FRAMEWORK_RENDER_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_RENDER_LOGGER_NAME)->trace(__VA_ARGS__);}
#define RENDER_DEBUG(...) if (spdlog::get(FRAMEWORK_RENDER_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_RENDER_LOGGER_NAME)->debug(__VA_ARGS__);}
#define RENDER_INFO(...) if (spdlog::get(FRAMEWORK_RENDER_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_RENDER_LOGGER_NAME)->info(__VA_ARGS__);}
#define RENDER_WARN(...) if (spdlog::get(FRAMEWORK_RENDER_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_RENDER_LOGGER_NAME)->warn(__VA_ARGS__);}
#define RENDER_ERROR(...) if (spdlog::get(FRAMEWORK_RENDER_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_RENDER_LOGGER_NAME)->error(__VA_ARGS__);}
#define RENDER_CRITICAL(...) if (spdlog::get(FRAMEWORK_RENDER_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_RENDER_LOGGER_NAME)->critical(__VA_ARGS__);}

#define TEXTURE_TRACE(...) if (spdlog::get(FRAMEWORK_TEXTURE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_TEXTURE_LOGGER_NAME)->trace(__VA_ARGS__);}
#define TEXTURE_DEBUG(...) if (spdlog::get(FRAMEWORK_TEXTURE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_TEXTURE_LOGGER_NAME)->debug(__VA_ARGS__);}
#define TEXTURE_INFO(...) if (spdlog::get(FRAMEWORK_TEXTURE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_TEXTURE_LOGGER_NAME)->info(__VA_ARGS__);}
#define TEXTURE_WARN(...) if (spdlog::get(FRAMEWORK_TEXTURE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_TEXTURE_LOGGER_NAME)->warn(__VA_ARGS__);}
#define TEXTURE_ERROR(...) if (spdlog::get(FRAMEWORK_TEXTURE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_TEXTURE_LOGGER_NAME)->error(__VA_ARGS__);}
#define TEXTURE_CRITICAL(...) if (spdlog::get(FRAMEWORK_TEXTURE_LOGGER_NAME) != nullptr) {spdlog::get(FRAMEWORK_TEXTURE_LOGGER_NAME)->critical(__VA_ARGS__);}
