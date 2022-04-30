# SimpleLoggingCPP
A simple C++11 compatible logging library supporting five levels of logging and multiple streams per level. 

## How to use
Include `logging.h` file, optionally define `LOGGING_EXTRA_DEFINES` before including so you dont have to type this: `Logging::getLogger(LogLevel::LOG_INFO)`.

There are five log levels:
`DEBUG, INFO, WARN, ERROR, CRITICAL`
