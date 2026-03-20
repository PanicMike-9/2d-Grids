#pragma once
#include <string>

namespace ansi
{
    // color normal foreground
    constexpr const char* black = "\033[30m";
    constexpr const char* red = "\033[31m";
    constexpr const char* green = "\033[32m";
    constexpr const char* yellow = "\033[33m";
    constexpr const char* blue = "\033[34m";
    constexpr const char* magenta = "\033[35m";
    constexpr const char* cyan = "\033[36m";
    constexpr const char* white = "\033[37m";

    // color bright foreground
    constexpr const char* bright_black = "\033[90m";
    constexpr const char* bright_red = "\033[91m";
    constexpr const char* bright_green = "\033[92m";
    constexpr const char* bright_yellow = "\033[93m";
    constexpr const char* bright_blue = "\033[94m";
    constexpr const char* bright_magenta = "\033[95m";
    constexpr const char* bright_cyan = "\033[96m";
    constexpr const char* bright_white = "\033[97m";

    // cursor position
    inline std::string move(int row, int col)
    {
        return "\033[" + std::to_string(row) + ";" 
                       + std::to_string(col) + "H";
    }

    // clear screen
    constexpr const char* clear_screen = "\033[2J\033[H";

    // reset all
    constexpr const char* reset = "\033[0m";
}
