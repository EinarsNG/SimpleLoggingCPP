#include <iostream>
#include <fstream>

#define LOGGING_EXTRA_DEFINES
#include "logging/logging.h"

int main()
{
    // With defines
    std::ofstream ofs("test.log");
    _INFO_.addStream(&ofs);
    _INFO_.addStream(&std::cout);
    _INFO_ << "This string of text will apear on both std::cout and in test.log file";
    _INFO_.removeStream(&std::cout);
    _INFO_ << "This string of text will only appear in test.log file";

    // Without defines
    /*
    std::ofstream ofs("test.log");
    Logger::getLogger(LogLevel::LOG_INFO).addStream(&ofs);
    Logger::getLogger(LogLevel::LOG_INFO).addStream(&std::cout);
    Logger::getLogger(LogLevel::LOG_INFO) << "This string of text will apear on both std::cout and in test.log file";
    Logger::getLogger(LogLevel::LOG_INFO).removeStream(&std::cout);
    Logger::getLogger(LogLevel::LOG_INFO) << "This string of text will only appear in test.log file";
    */
}
