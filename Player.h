#ifndef PLAYER_H
#define PLAYER_H
#include "KeyHandler.h"
#include <bits/stdc++.h>
#include <pthread.h>
#include <utility>
#include <semaphore.h>
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
    ~Player();
};
#endif