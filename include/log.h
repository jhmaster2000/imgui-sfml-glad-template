#pragma once

#define PLOG_PRINT_SEVERITY
#define PLOG_PRINT_FUNCTION_LINE

#include <filesystem>
#include <plog/Log.h>
#include <plog/Init.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Appenders/RollingFileAppender.h>

class Logger {
    Logger() = delete;

public:
    static inline bool inited = false;
    static void init(plog::Severity logLevel = plog::verbose, const char* logFilePath = NULL, bool logConsole = true, bool clearPrevLogFile = true) {
        if (inited || (!logFilePath && !logConsole)) return;
        inited = true;

        if (logFilePath && clearPrevLogFile) std::filesystem::remove(logFilePath);

        static plog::RollingFileAppender<plog::TxtFormatter> fileAppender("TEMP");
        static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;

        if (logFilePath) {
            fileAppender.setFileName(logFilePath);
            if (logConsole) plog::init(logLevel, &fileAppender).addAppender(&consoleAppender);
            else plog::init(logLevel, &fileAppender);
        } else plog::init(logLevel, &consoleAppender);
    }
};
