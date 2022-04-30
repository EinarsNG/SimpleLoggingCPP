# SimpleLoggingCPP
A simple C++11 compatible logging library supporting five levels of logging and multiple streams per level. 

## How to use
Include `logging.h` file, optionally define `LOGGING_EXTRA_DEFINES` before including so you dont have to type this: `Logging::getLogger(LogLevel::LOG_INFO)`.

There are five log levels:
`DEBUG, INFO, WARN, ERROR, CRITICAL`

Example:
```
#include <iostream>
#include <fstream>

#define LOGGING_EXTRA_DEFINES
#include "logging/logging.h"

int main()
{
    std::ofstream ofs("test.log");
    _INFO_.addStream(&ofs);
    _INFO_.addStream(&std::cout);
    _INFO_ << "This string of text will apear on both std::cout and in test.log file";
    _INFO_.removeStream(&std::cout);
    _INFO_ << "This string of text will only appear in test.log file";
}
```
