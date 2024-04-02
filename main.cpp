#include <bits/stdc++.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <utility>
#include <pthread.h>
using namespace std;
static struct termios t;

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
string get_input(){
    string result = "None";
    char user_input;
    cin >> user_input;
    switch (user_input)
    {
    case 'a':
        result = "West";
        break;
    case 'w':
        result = "North";
        break;
    case 'd':
        result = "East";
        break;
    case 's':
        result = "South";
        break;
    }
    return result;
}
static int exit_loop;


int main() {
    configure_terminal();


    while (!exit_loop) {
        string key = get_input();
        cout << key << endl;

    }
    
}