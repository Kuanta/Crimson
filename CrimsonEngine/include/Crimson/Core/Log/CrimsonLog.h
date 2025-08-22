#pragma once
#include <memory>
#include "Crimson/Core/Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Crimson
{
    class CRIMSON_API CrimsonLog
    {
        public:
        CrimsonLog();
        ~CrimsonLog();

        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){return s_CoreLogger;}
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){return s_ClientLogger;}

        private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

//Core log macros
#define CR_CORE_TRACE(...)::Crimson::CrimsonLog::GetCoreLogger()->trace(__VA_ARGS__)
#define CR_CORE_INFO(...)::Crimson::CrimsonLog::GetCoreLogger()->info(__VA_ARGS__)
#define CR_CORE_WARN(...)::Crimson::CrimsonLog::GetCoreLogger()->warn(__VA_ARGS__)
#define CR_CORE_ERROR(...)::Crimson::CrimsonLog::GetCoreLogger()->error(__VA_ARGS__)

//Client log mactros
#define CR_TRACE(...)::Crimson::CrimsonLog::GetClientLogger()->trace(__VA_ARGS__)
#define CR_INFO(...)::Crimson::CrimsonLog::GetClientLogger()->info(__VA_ARGS__)
#define CR_WARN(...)::Crimson::CrimsonLog::GetClientLogger()->warn(__VA_ARGS__)
#define CR_ERROR(...)::Crimson::CrimsonLog::GetClientLogger()->error(__VA_ARGS__)