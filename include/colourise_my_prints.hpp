#ifndef COLOURISE_MY_PRINTS_HPP
#define COLOURISE_MY_PRINTS_HPP

// Text color:
#define BLACK "\033[30m"
#define RED "\033[31m"
#define ORANGE "\033[38;2;255;165;0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define VIOLET "\033[38;2;75;0;130m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define LIGHT_GRAY "\033[37m"
#define DARK_GRAY "\033[90m"
#define LIGHT_RED "\033[91m"
#define LIGHT_GREEN "\033[92m"
#define LIGHT_YELLOW "\033[93m"
#define LIGHT_BLUE "\033[94m"
#define LIGHT_MAGENTA "\033[95m"
#define LIGHT_CYAN "\033[96m"
#define WHITE "\033[97m"

// Background color:
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_LIGHT_GRAY "\033[47m"
#define BG_DARK_GRAY "\033[100m"
#define BG_LIGHT_RED "\033[101m"
#define BG_LIGHT_GREEN "\033[102m"
#define BG_LIGHT_YELLOW "\033[103m"
#define BG_LIGHT_BLUE "\033[104m"
#define BG_LIGHT_MAGENTA "\033[105m"
#define BG_LIGHT_CYAN "\033[106m"
#define BG_WHITE "\033[107m"

// Formatting options:
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define BLINK "\033[5m"
#define REVERSE "\033[7m"
#define HIDDEN "\033[8m"
#define STRIKETHROUGH "\033[9m"

#endif