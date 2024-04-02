#ifndef KEYHANDLER_H
#define KEYHANDLER_H
#include <termios.h>
enum Direction {
    Error = -1,
    West = 0,
    North = 1,
    East = 2,
    South = 3
};
class KeyHandler
{
private:
    struct termios t;
    void reset_terminal();
    void configure_terminal();
public:
    KeyHandler();
    ~KeyHandler();
    enum Direction get_input();
};

#endif