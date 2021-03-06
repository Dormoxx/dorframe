#ifdef PLATFORM_SDL
#include "Log.h"
#include "../vendor/spdlog/include/spdlog/sinks/stdout_color_sinks.h"


namespace dorframe{

  std::shared_ptr<spdlog::logger> Log::s_Logger;

  void Log::Init(){
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_Logger = spdlog::stdout_color_mt("dorframe");
    s_Logger->set_level(spdlog::level::trace);
    DORFRAME_LOG_INFO("Initialzed Log.");
  }
}
#endif
