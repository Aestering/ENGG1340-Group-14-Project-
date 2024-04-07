#include <bits/stdc++.h>
#include <pthread.h>
#include <utility>
#include "Player.h"
using namespace std;
void *handle_thread(void *p){
    Player *player = (Player*)p;
    while (true)
    {
        player->update_direction();
    }
    
}
Player::Player(){
    x.resize(100, -1);
    y.resize(100, -1);
    x[0] = 1;
    y[0] = 1;
    pthread_create(&update_thread, NULL, handle_thread, this);
}
Player::~Player(){

}
void Player::update_direction(){
    Direction direction = key.get_input();
    this->direction = direction;
}
void Player::update_body(){
    for(int i = body; i > 0; i--){
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    } 
    if(direction == West){
        y[0]--;
    }
    if(direction == East){
        y[0]++;
    }
    if(direction == North){
        x[0]--;
    }
    if(direction == South){
        x[0]++;
    }
}