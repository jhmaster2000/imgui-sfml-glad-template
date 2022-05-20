#pragma once

namespace LogColor {
    constexpr const char* Reset        = "\33[0m";
    constexpr const char* Bold         = "\33[1m";
    constexpr const char* NoBold       = "\33[22m";
    constexpr const char* Underline    = "\33[4m";
    constexpr const char* NoUnderline  = "\33[24m";
    constexpr const char* Invert       = "\33[7m";
    constexpr const char* NoInvert     = "\33[27m";

    constexpr const char* Black        = "\33[30m";
    constexpr const char* Red          = "\33[31m";
    constexpr const char* Green        = "\33[32m";
    constexpr const char* Yellow       = "\33[33m";
    constexpr const char* Blue         = "\33[34m";
    constexpr const char* Magenta      = "\33[35m";
    constexpr const char* Cyan         = "\33[36m";
    constexpr const char* LightGray    = "\33[37m";
    constexpr const char* Gray         = "\33[90m";
    constexpr const char* LightRed     = "\33[91m";
    constexpr const char* LightGreen   = "\33[92m";
    constexpr const char* LightYellow  = "\33[93m";
    constexpr const char* LightBlue    = "\33[94m";
    constexpr const char* LightMagenta = "\33[95m";
    constexpr const char* LightCyan    = "\33[96m";
    constexpr const char* White        = "\33[97m";
    constexpr const char* Default      = "\33[39m";
    //constexpr const char* Extended     = "\33[38m";

    namespace BG {
        constexpr const char* Black        = "\33[40m";
        constexpr const char* Red          = "\33[41m";
        constexpr const char* Green        = "\33[42m";
        constexpr const char* Yellow       = "\33[43m";
        constexpr const char* Blue         = "\33[44m";
        constexpr const char* Magenta      = "\33[45m";
        constexpr const char* Cyan         = "\33[46m";
        constexpr const char* LightGray    = "\33[47m";
        constexpr const char* Gray         = "\33[100m";
        constexpr const char* LightRed     = "\33[101m";
        constexpr const char* LightGreen   = "\33[102m";
        constexpr const char* LightYellow  = "\33[103m";
        constexpr const char* LightBlue    = "\33[104m";
        constexpr const char* LightMagenta = "\33[105m";
        constexpr const char* LightCyan    = "\33[106m";
        constexpr const char* White        = "\33[107m";
        constexpr const char* Default      = "\33[49m";
        //constexpr const char* Extended     = "\33[48m";
    }
}
