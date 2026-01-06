#pragma once
#include <string>
#include <fstream>

class Logger {
public:
    explicit Logger(const std::string &filename = "run.log");
    ~Logger();

    void info(const std::string &msg);
    void warn(const std::string &msg);
    void error(const std::string &msg);
    void flush();

private:
    std::ofstream ofs_;
    void write(const std::string &level, const std::string &msg);
};
