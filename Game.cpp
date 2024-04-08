#include <iostream>
#include <vector> 
#include <unistd.h>
#include <iomanip>
#include "Bot.h"
#include "Game_Data.h"
#include "Player.h"
std::string board[] = {"000000000000000000000000000000000000000000000000000000",
                       "0                                                    0",
                       "0                                                    0",
                       "0                                                    0",
                       "0                                                    0",
                       "0                                                    0",
                       "0                                                    0",
                       "0                                                    0",
                       "0                                                    0",
                       "0                                                    0",
                       "0                                                    0",
                       "000000000000000000000000000000000000000000000000000000"};
int run_game() {
    Player player;
    Bot bot;
    int appleX, appleY;
    int timer = 100;
    double t = 0;

    srand(time(NULL));
    appleX = rand() % (HEIGHT - 2) + 1;
    appleY = rand() % (WIDTH - 2) + 1;
    while (true) {
        player.draw(board);
        bot.draw(board);
        board[appleX][appleY] = APPLE;
        std::cout << std::left << std::setw(20) << player.body - 3 << std::setw(20) << timer << std::setw(20) << bot.body - 3 << std::endl;
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if(board[i][j] == SNAKE_BODY) std::cout << YELLOW << BLOCK;
                else if(board[i][j] == BOT_BODY) std::cout << RED << BLOCK;
                else if(board[i][j] == WALL) std::cout << BLUE << BLOCK << RESET;
                else if(board[i][j] == APPLE) std::cout << RED << CIRCLE << RESET;
                else std::cout << board[i][j] << RESET;
            }
            std::cout << std::endl;
        }
        player.update_body();
        bot.update_direction(player, appleX, appleY);
        bot.update_body();
        if(player.check_apple(appleX, appleY) || bot.check_apple(appleX, appleY)){
            appleX = rand() % (HEIGHT - 2) + 1;
            appleY = rand() % (WIDTH - 2) + 1;
        }
        if(timer == 0){
            if(player.body > bot.body) return 0;
            else if(player.body < bot.body) return 1;
            else return 2;
        }
        usleep(1000 * 100);
        t += 0.1;
        system("clear");
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if(board[i][j] != WALL) board[i][j] = ' ';
                else board[i][j] = WALL;
            }
        }
        
        if(t >= 1 && timer > 0){
            t = 0;
            timer--;
        }
    }    
}