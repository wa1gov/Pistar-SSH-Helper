// USING ANSI COLORS

static std::map<std::string, std::string> colors = {
    { "BLACK", "\x1b[30m" },
    { "BBLACK", "\x1b[90m" },
    { "RED", "\x1b[31m" },
    { "BRED", "\x1b[91m" },
    { "GREEN", "\x1b[32m" },
    { "BGREEN", "\x1b[92m" },
    { "YELLOW", "\x1b[33m" },
    { "BYELLOW", "\x1b[93m" },
    { "BLUE", "\x1b[34m" },
    { "BBLUE", "\x1b[94m" },
    { "MAGENTA", "\x1b[35m" },
    { "BMAGENTA", "\x1b[95m" },
    { "CYAN", "\x1b[36m" },
    { "BCYAN", "\x1b[96m" },
    { "WHITE", "\x1b[37m" },
    { "BWHITE", "\x1b[97m" },
    { "OnBlack", "\x1b[40m" },
    { "OnRed", "\x1b[41m" },
    { "OnGreen", "\x1b[42m" },
    { "OnYellow", "\x1b[43m" },
    { "OnBlue", "\x1b[44m" },
    { "OnPurple", "\x1b[45m" },
    { "OnCyan", "\x1b[46m" },
    { "OnWhite", "\x1b[47m" }, 
    { "OnAmber", "\x1b[38;5;16;48;5;172m" } 
};
static const std::string RESET="\x1b[0m";
