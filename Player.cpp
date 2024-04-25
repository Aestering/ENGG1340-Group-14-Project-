#include <iostream>
#include <pthread.h>
#include <vector>
#include <utility>
#include <algorithm>
#include "Game_Data.h"
#include "Player.h"
enum Direction get_input(){
    char user_input = getchar();
    tolower(user_input);
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
bool thread_running = true;
bool islegible(Direction before, Direction after){
    return (std::max(before, after) - std::min(before, after)) != 2;
}
void *handle_thread(void *p){
    struct Player *player = (Player*)p;
    while (thread_running)
    {
        player->update_direction();
    }
    pthread_exit(NULL); 
}
Player::Player(){
    x.resize(100, -1);
    y.resize(100, -1);
    thread_running = true;
    x[0] = 1;
    y[0] = 1;
    pthread_create(&update_thread, NULL, handle_thread, this);
}
Player::~Player(){
    thread_running = false;
}

void Player::update_direction(){
    
    Direction direction = get_input();
    if(direction != Error && islegible(this->direction, direction)) this->direction = direction;

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
    if(x[0] >= HEIGHT - 1) x[0] = 1; 
    if(x[0] <= 0) x[0] = HEIGHT - 2;
    if(y[0] >= WIDTH - 1) y[0] = 1; 
    if(y[0] <= 0) y[0] = WIDTH - 2;
}

//if the player eats the apple the body length increases 
bool Player::check_apple(int appleX, int appleY){
    if(x[0] == appleX && y[0] == appleY){
        body++;
        return true;
    }
    return false;
}
void Player::draw(std::string (&board)[HEIGHT]){
    for(int i = 0; i < body; i++){
        if(x[i] == -1 || y[i] == -1) continue;
        if(board[x[i]][y[i]] == VOID) board[x[i]][y[i]] = SNAKE_BODY;
    }
}