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
