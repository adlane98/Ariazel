#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Ariazel {
	class ARIAZEL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


// Core log macros
#define AZ_CORE_TRACE(...)	Ariazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AZ_CORE_INFO(...)	Ariazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AZ_CORE_WARN(...)	Ariazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AZ_CORE_ERROR(...)	Ariazel::Log::GetCoreLogger()->error(__VA_ARGS__)



// Client log macros
#define AZ_TRACE(...)		Ariazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AZ_INFO(...)		Ariazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define AZ_WARN(...)		Ariazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AZ_ERROR(...)		Ariazel::Log::GetClientLogger()->error(__VA_ARGS__)
