#ifndef LOGGING_H
#define LOGGING_H

#ifdef LOGGING_EXTRA_DEFINES
#define _DEBUG_		Logger::getLogger(LogLevel::LOG_DEBUG)
#define _INFO_		Logger::getLogger(LogLevel::LOG_INFO)
#define _WARN_		Logger::getLogger(LogLevel::LOG_WARN)
#define _ERROR_		Logger::getLogger(LogLevel::LOG_ERROR)
#define _CRITICAL_	Logger::getLogger(LogLevel::LOG_CRITICAL)
#endif

#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>

enum LogLevel
{
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_CRITICAL,
};

class LoggerInstance
{
private:
    std::string			name;
    LogLevel			logLevel;
    std::vector<std::ostream*>	streams;
    std::mutex			streamMtx;

    std::string logLevelStr() noexcept;
    std::string formatLog(std::string& msg) noexcept;
public:
    LoggerInstance(LogLevel logLevel);

    void operator<<(std::string msg);

    void addStream(std::ostream* stream);
    void removeStream(std::ostream* stream);
};

class Logger
{
private:
    std::unordered_map<LogLevel, LoggerInstance*> loggers;

    Logger() {};
    static Logger& getInstance();
public:
    Logger(Logger const&) 		= delete;
    void operator=(Logger const&) 	= delete;

    static LoggerInstance& getLogger(LogLevel logLevel);
};
#endif
