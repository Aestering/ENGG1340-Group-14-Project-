#ifndef PLAYER_H
#define PLAYER_H
#include "KeyHandler.h"
#include "Game_Data.h"
#include <string>
#include <pthread.h>

class Player
{
private:
    KeyHandler key;
    Direction direction = East;
    pthread_t update_thread;
    int body = 3;
public:
    std::vector<int> x, y;
    Player();
    void update_direction();
    void update_body();
    bool check(int, int);
    void draw(std::string (&board)[HEIGHT]);
    ~Player();
};
#endif