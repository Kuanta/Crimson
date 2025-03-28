#pragma once

#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <memory>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <filesystem>
#include <unordered_map>


#define FMT_HEADER_ONLY

#ifndef SPDLOG_FMT_EXTERNAL
    #define SPDLOG_FMT_EXTERNAL
#endif

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

// CRIMSON_API tanımı: Export/Import ayarları
#ifdef CRIMSON_EXPORT
    #ifdef _MSC_VER
        #define CRIMSON_API __declspec(dllexport)
    #else
        #define CRIMSON_API __attribute__((visibility("default")))
    #endif
#else
    #ifdef _MSC_VER
        #define CRIMSON_API __declspec(dllimport)
    #else
        #define CRIMSON_API
    #endif
#endif

#define CRIMSON_ASSERT assert

// Static assert tanımı (isim hatası giderildi)
#if defined(__clang__) || defined(__gcc__)
    #define CRIMSON_STATIC_ASSERT _Static_assert
#else
    #define CRIMSON_STATIC_ASSERT static_assert
#endif

// Inline ve noinline tanımlamaları
#if defined(__clang__) || defined(__gcc__)
    #define CRIMSON_INLINE __attribute__((always_inline)) inline
    #define CRIMSON_NOINLINE __attribute__((noinline))
#elif defined(_MSC_VER)
    #define CRIMSON_INLINE __forceinline
    #define CRIMSON_NOINLINE __declspec(noinline)
#else
    #define CRIMSON_INLINE inline
    #define CRIMSON_NOINLINE
#endif 

// Console Logging
#ifdef CRIMSON_ENABLE_LOG
    namespace Crimson
    {
        struct CRIMSON_API Logger
        {
            using SPDLog = std::shared_ptr<spdlog::logger>;
            CRIMSON_INLINE Logger()
            {
                m_SPD = spdlog::stdout_color_mt("stdout");
                spdlog::set_level(spdlog::level::trace);
                spdlog::set_pattern("%^[%T]: [#%t] %v%$");
            }

            CRIMSON_INLINE static SPDLog& Ref()
            {
                static Logger logger;
                return logger.m_SPD;
            }
        private:
            SPDLog m_SPD;
        };
    }

    #define CRIMSON_TRACE(...) Crimson::Logger::Ref()->trace(__VA_ARGS__)
    #define CRIMSON_DEBUG(...) Crimson::Logger::Ref()->debug(__VA_ARGS__)
    #define CRIMSON_INFO(...) Crimson::Logger::Ref()->info(__VA_ARGS__)
    #define CRIMSON_WARN(...) Crimson::Logger::Ref()->warn(__VA_ARGS__)
    #define CRIMSON_ERROR(...) Crimson::Logger::Ref()->error(__VA_ARGS__)
    #define CRIMSON_FATAL(...) Crimson::Logger::Ref()->critical(__VA_ARGS__)
#else
    #define CRIMSON_TRACE
    #define CRIMSON_DEBUG
    #define CRIMSON_INFO
    #define CRIMSON_WARN
    #define CRIMSON_ERROR
    #define CRIMSON_FATAL
#endif

namespace Crimson
{
    template <typename T>
    CRIMSON_INLINE constexpr uint32_t TypeID()
    {
        return static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(&typeid(T)));
    }
}

#define CRIMSON_DELETE(ptr) do { if(ptr != nullptr){ delete(ptr); ptr = nullptr; } } while(0)
