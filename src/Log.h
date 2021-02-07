#ifdef PLATFORM_SDL
#ifndef  LOG_H_
#define LOG_H_

#include <memory>
#include <spdlog/spdlog.h>
namespace dorframe{
  class Log{
  //private:

  public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetLogger() {return s_Logger;}

  private:
    static std::shared_ptr<spdlog::logger> s_Logger;

  };

}

#define DORFRAME_LOG_TRACE(...) ::dorframe::Log::GetLogger()->trace(__VA_ARGS__)
#define DORFRAME_LOG_INFO(...)  ::dorframe::Log::GetLogger()->info(__VA_ARGS__)
#define DORFRAME_LOG_WARN(...)  ::dorframe::Log::GetLogger()->warn(__VA_ARGS__)
#define DORFRAME_LOG_ERROR(...) ::dorframe::Log::GetLogger()->error(__VA_ARGS__)
#define DORFRAME_LOG_FATAL(...) ::dorframe::Log::GetLogger()->fatal(__VA_ARGS__)

#endif /* end of include guard: LOG_H_ */
#endif
