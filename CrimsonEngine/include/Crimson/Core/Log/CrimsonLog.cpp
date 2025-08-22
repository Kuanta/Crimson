#include "Crimson/Core/Log/CrimsonLog.h"

namespace Crimson
{
    std::shared_ptr<spdlog::logger> CrimsonLog::s_CoreLogger;
    std::shared_ptr<spdlog::logger> CrimsonLog::s_ClientLogger;
    
    void CrimsonLog::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("Crimson");
        s_CoreLogger->set_level(spdlog::level::trace);
        s_ClientLogger = spdlog::stdout_color_mt("App");
         s_CoreLogger->set_level(spdlog::level::trace);
    }

    CrimsonLog::CrimsonLog()
    {

    }
    CrimsonLog::~CrimsonLog()
    {

    }
}