#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "KeyHandler.h"
void KeyHandler::reset_terminal(){
    printf("\e[m"); // reset color changes
    printf("\e[?25h"); // show cursor
    fflush(stdout);
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

}
void KeyHandler :: configure_terminal(){
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    printf("\e[?25l"); // hide cursor
}
enum Direction KeyHandler :: get_input(){
    char user_input = getchar();
    switch (user_input)
    {
    case 'a':
        return West;
        break;
    case 'w':
        return North;
        break;
    case 'd':
        return East;
        break;
    case 's':
        return South;
        break;
    }
    return Error;
}