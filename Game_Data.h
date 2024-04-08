#ifndef GAME_DATA_H
#define GAME_DATA_H
#include <string>
#include <pthread.h>
enum Glyphs{
    VOID = ' ',
    WALL = '0',
    SNAKE_BODY = '1',
    APPLE = '2',
    BOT_BODY = '3'
};
enum Direction {
    Error = -1,
    West = 0,
    North = 1,
    East = 2,
    South = 3
};
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string RESET = "\033[0m";
const std::string BLOCK = "\u2588";
const std::string SHADE = "\u2591";
const std::string CIRCLE = "\u25CF";
const int WIDTH = 54;
const int HEIGHT = 12;
#endif