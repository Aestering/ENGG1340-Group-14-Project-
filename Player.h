#ifndef PLAYER_H
#define PLAYER_H
#include "Game_Data.h"
#include <string>
#include <vector>
#include <pthread.h>
class Player
{
private:
    Direction direction = East;
    pthread_t update_thread;
public:
    std::vector<int> x, y;
    int body = 3;
    Player();
    void update_direction();
    void update_body();
    bool check_apple(int, int);
    void draw(std::string (&board)[HEIGHT]);
    ~Player();
};
#endif