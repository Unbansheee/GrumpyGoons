#pragma once
#include <string>

enum LogType
{
    INFO,
    WARNING,
    ERROR
};

class Log
{
public:
    static void Print(const std::string& message, LogType type = LogType::INFO);
    
};
