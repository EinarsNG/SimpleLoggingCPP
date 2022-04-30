#include <algorithm>
#include <time.h>
#include <sstream>
#include <iomanip>
#include "logging.h"

// LoggerInstance

static std::string getTime()
{
    time_t rawtime;
    time(&rawtime);
    tm * timeinfo = localtime(&rawtime);
    char buffer[32];
    strftime(buffer, 32, "%F %T", timeinfo);
    return std::string(buffer);
}

LoggerInstance::LoggerInstance(LogLevel logLevel)
    : logLevel(logLevel)
{}

std::string LoggerInstance::logLevelStr() noexcept
{
    switch(logLevel)
    {
    case LogLevel::LOG_DEBUG:
        return "DEBUG";
    case LogLevel::LOG_INFO:
        return "INFO";
    case LogLevel::LOG_WARN:
        return "WARNING";
    case LogLevel::LOG_ERROR:
        return "ERROR";
    case LogLevel::LOG_CRITICAL:
        return "CRITICAL";
    default:
        return "";
    }
}

std::string LoggerInstance::formatLog(std::string& msg) noexcept
{
    std::stringstream ss;
    ss << std::left << std::setw(22) << "[" + getTime() + "]"
       << "|" << std::setw(8) << logLevelStr() << "| "
       << msg << "\n";
    return ss.str();
}

void LoggerInstance::operator<<(std::string msg)
{
    for(auto & stream : streams)
        *stream << formatLog(msg);
}

void LoggerInstance::addStream(std::ostream* stream)
{
    streams.push_back(stream);
}

void LoggerInstance::removeStream(std::ostream *stream)
{
    auto it = std::find(streams.begin(), streams.end(), stream);
    if (it == streams.end())
        return;
    streams.erase(it);
}

// Logger

Logger& Logger::getInstance()
{
    static Logger inst;
    return inst;
}

LoggerInstance& Logger::getLogger(LogLevel logLevel)
{
    auto it = getInstance().loggers.find(logLevel);
    if (it == getInstance().loggers.end())
    {
        LoggerInstance * logger = new LoggerInstance(logLevel);
        getInstance().loggers[logLevel] = logger;
        return *logger;
    }
    return *it->second;
}
