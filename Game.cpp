#include <iostream>
#include <vector> 
#include <unistd.h>
#include <iomanip>
#include "Bot.h"
#include "Game_Data.h"
#include "Player.h"
std::string board[] = {"00000000000000000000000000000000000000000000000000",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "0                                                0",
                       "00000000000000000000000000000000000000000000000000"};
int run_game(int difficulty) {
    Player player;
    Bot bot;
    int appleX, appleY;
    int timer = 100;
    double t = 0;

    srand(time(NULL));
    appleX = rand() % (HEIGHT - 2) + 1;
    appleY = rand() % (WIDTH - 2) + 1;
    while (true) {

        //drawing the glyphs
        player.draw(board);
        bot.draw(board);
        board[appleX][appleY] = APPLE;

        //print the scores
        std::cout << std::left  << "Your Score: "<< std::setw(7) <<player.body - 3  << "Time: "<< std::setw(7) << timer  << "Opponent's score: "<< std::setw(7) << bot.body - 3 << std::endl;

        //printing the board
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

        //updating the positions
        player.update_body();
        bot.update_direction(appleX, appleY, difficulty);
        bot.update_body();

        //checking whether either of snakes ate the apple
        if(player.check_apple(appleX, appleY) || bot.check_apple(appleX, appleY)){
            appleX = rand() % (HEIGHT - 2) + 1;
            appleY = rand() % (WIDTH - 2) + 1;
        }

        //if time goes off the game ends
        if(timer == 0){
            if(player.body > bot.body) return 0;
            else if(player.body < bot.body) return 1;
            else return 2;
        }


        usleep(1000 * 100);
        t += 0.1;

        //reset the board
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