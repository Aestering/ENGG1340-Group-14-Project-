#include <bits/stdc++.h>
#include <termios.h>
#include <unistd.h>
using namespace std;
class KeyHandler
{
private:
    /* data */
public:
    bool up = false, left = false, right = false, down = false;
    bool getUp();
    bool getDown();
    bool getLeft();
    bool getRight();
};
bool KeyHandler::getUp()
{
    return up;
}
bool KeyHandler::getDown()
{
    return down;
}
bool KeyHandler::getLeft()
{
    return left;
}
bool KeyHandler::getRight()
{
    return right;
}
void reset_terminal(){
    printf("\e[m"); // reset color changes
    printf("\e[?25h"); // show cursor
    fflush(stdout);

    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}
void configure_terminal(){
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    printf("\e[?25l"); // hide cursor
    atexit(reset_terminal);
}