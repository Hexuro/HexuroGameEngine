#ifndef _HEXURO_LOG_
#define _HEXURO_LOG_

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Hexuro {
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetGameLogger() { return s_GameLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_EngineLogger;
        static std::shared_ptr<spdlog::logger> s_GameLogger;
    };

}

#define HX_ENGINE_TRACE(...) Hexuro::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define HX_ENGINE_INFO(...)  Hexuro::Log::GetEngineLogger()->info(__VA_ARGS__)
#define HX_ENGINE_WARN(...)  Hexuro::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define HX_ENGINE_ERROR(...) Hexuro::Log::GetEngineLogger()->error(__VA_ARGS__)
#define HX_ENGINE_FATAL(...) Hexuro::Log::GetEngineLogger()->critical(__VA_ARGS__)

#define HX_GAME_TRACE(...)   Hexuro::Log::GetGameLogger()->trace(__VA_ARGS__)
#define HX_GAME_INFO(...)    Hexuro::Log::GetGameLogger()->info(__VA_ARGS__)
#define HX_GAME_WARN(...)    Hexuro::Log::GetGameLogger()->warn(__VA_ARGS__)
#define HX_GAME_ERROR(...)   Hexuro::Log::GetGameLogger()->error(__VA_ARGS__)
#define HX_GAME_FATAL(...)   Hexuro::Log::GetGameLogger()->critical(__VA_ARGS__)

#endif // !_HEXURO_LOG_