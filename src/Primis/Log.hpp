#pragma once

#include <memory>
#include "spdlog/spdlog.h"

namespace Primis
{
    class Log
    {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger(){return s_CoreLogger;};
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger(){return s_ClientLogger;};

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
};

#define PRIMIS_INFO_LOG(...)  Primis::Log::GetCoreLogger()->info(__VA_ARGS__);
#define PRIMIS_WARN_LOG(...)  Primis::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define PRIMIS_ERROR_LOG(...) Primis::Log::GetCoreLogger()->error(__VA_ARGS__);