#include "logger.h"
#include <iostream>
#include <chrono>
#include <ctime>

Logger::Logger(const std::string &filename) {
    ofs_.open(filename, std::ios::app);
}

Logger::~Logger() {
    flush();
    if (ofs_.is_open()) ofs_.close();
}

void Logger::write(const std::string &level, const std::string &msg) {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    char timebuf[32];
    std::strftime(timebuf, sizeof(timebuf),
                  "%Y-%m-%d %H:%M:%S",
                  std::localtime(&t));

    std::string line = std::string(timebuf) +
                       " [" + level + "] " + msg;

    std::cout << line << std::endl;
    if (ofs_) ofs_ << line << std::endl;
}

void Logger::info(const std::string &msg)  { write("INFO", msg); }
void Logger::warn(const std::string &msg)  { write("WARN", msg); }
void Logger::error(const std::string &msg) { write("ERROR", msg); }
void Logger::flush() {
    if (ofs_) ofs_.flush();
}
