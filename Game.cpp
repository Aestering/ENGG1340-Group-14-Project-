#include <iostream>
#include <vector> 
#include <unistd.h>
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
void run() {
    Player player;
    Bot bot;
    int appleX, appleY;
    srand(time(NULL));
    appleX = rand() % (HEIGHT - 2) + 1;
    appleY = rand() % (WIDTH - 2) + 1;
    while (true) {
        player.draw(board);
        bot.draw(board);
        board[appleX][appleY] = APPLE;
        
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
        if(bot.check_collision(player)){
            return;
        }
        usleep(1000 * 100);

        system("clear");
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if(board[i][j] != WALL) board[i][j] = ' ';
                else board[i][j] = WALL;
            }
        }
    }    
}