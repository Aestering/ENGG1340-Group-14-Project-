#include <bits/stdc++.h>
#include <unistd.h>
#include "KeyHandler.h"
#include "Player.h"
#include "Game_Data.h"
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
int main() {
    KeyHandler key;
    Player player;
    int appleX, appleY;
    srand(time(NULL));
    appleX = rand() % (HEIGHT - 2) + 1;
    appleY = rand() % (WIDTH - 2) + 1;
    while (true) {
        player.draw(board);
        board[appleX][appleY] = APPLE;
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if(board[i][j] == SNAKE_BODY) std::cout << RED << BLOCK;
                else if(board[i][j] == WALL) std::cout << BLUE << SHADE << RESET;
                else if(board[i][j] == APPLE) std::cout << RED << CIRCLE << RESET;
                else std::cout << board[i][j] << RESET;
            }
            std::cout << std::endl;
        }

        player.update_body();
        if(player.check(appleX, appleY)){
            appleX = rand() % (HEIGHT - 1) + 1;
            appleY = rand() % (WIDTH - 1) + 1;
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