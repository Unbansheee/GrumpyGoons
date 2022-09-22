#include "Log.h"

#include <iostream>

void Log::Print(const std::string& message, LogType type)
{
    switch (type)
    {
    case INFO:
        std::cout << "INFO: ";
        break;
        
    case WARNING:
        std::cout << "WARNING: ";
        break;
        
    case ERROR:
        std::cout << "ERROR: ";
        break;
        
    default:
        std::cout << "LOG: ";
        break;
    }

    std::cout << message << std::endl;
}
