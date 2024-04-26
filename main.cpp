#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "Game.h"
#include "Game_Data.h"
#include <chrono>
#include <thread>
using namespace std;
struct termios t;

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
}

void printWithSuspense(const string& text, int delayMs) {
    // implementing story-style way of showing the story by printing letter by letter
    for (char c : text) { 
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}
void printTheDifficultyMenu(int difficulty){
    std::cout << "=== Difficulty Menu ===" << std::endl;
    for (int i = 1; i <= 5; i++) {
        if (i == difficulty) {
            std::cout << "> ";
        }
        std::cout << i << ". ";
        switch (i) {
            case 1:
                std::cout << "Beginner";
                break;
            case 2:
                std::cout << "Easy";
                break;
            case 3:
                std::cout << "Normal";
                break;
            case 4:
                std::cout << "Hard";
                break;
            case 5:
                std::cout << "Insane";
                break;
        }
        std::cout << std::endl;
    }
}
int main() {
    int choice = 1, difficulty = 1;
    bool exitMenu = false;
    int delay1 = 50; // print timing for the story and instructions respectively
    int delay2 = 15; 

    string story = "In the aftermath of World War 3, the world was ravaged by a perpetual nuclear winter that has stripped the land and seas of natural resources.\n"
                       "Radioactive mutants emerged, placing humans at the bottom of the food chain.\n"
                       "Constant famines, unknown diseases, and the everlasting cycle of hatred...\n"
                       "Mankind was on the brink of destruction.\n...\n"
                       "A uranium-powered village hidden underneath the desolate sandy dunes inhabited sentient colossal snakes that segregated themselves from humans.\n"
                       "It all changed when Reggin, a boy whose brain structure was altered by radiation, was born.\n"
                       "At birth, his presence shifted the balance of the world as he converted the radiation around him into psychic powers.\n"
                       "The snakes, who were once hostile towards humans, were drawn to Reggin's Aura as he was the only human who could communicate with snakes.\n"
                       "Reggin bridged the gap between humans and snakes, and lived in coexistence.\n"
                       "Hailed as the village chief, Reggin reigned over the village, blessed with prosperity for a hundred years until his death.\n"
                       "On his last day, he received a vision that foretold of the village's future.\n"
                       "It was prophesied that the snakes would lead a warrior to the earth's core, where the last remaining resources are hidden.\n"
                       "You, a candidate in the snake warrior selection test, will compete with other candidates and achieve the right to save humanity once and for all.\n"
                       "The village chief has spoken, and the selection test begins!\n";

    string tutorial = "Use the WASD keys to change your snake's moving direction.\n"
                       "There are apples scattered around the map, consume more apples than your opponent within the time limit.\n"
                       "Choose your difficulty wisely, it might be too hard for you!\n"
                       "Good luck, snake warrior!\n";

    configure_terminal();

    // Print the menu once
    cout << CYAN << "███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗     ██████╗  █████╗ ███╗   ███╗███████╗" << endl;
    cout << "██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝" << endl;
    cout << "███████╗██╔██╗ ██║███████║█████╔╝ █████╗      ██║  ███╗███████║██╔████╔██║█████╗  " << endl;
    cout << "╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝      ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  " << endl;
    cout << "███████║██║ ╚████║██║  ██║██║  ██╗███████╗    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗" << endl;
    cout << "╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝" <<  RESET << endl;


    cout << "=== Main Menu ===" << endl;
    cout << "1. Play" << endl;
    cout << "2. Story" << endl;
    cout << "3. Tutorial" << endl;
    cout << "4. Difficulty" << endl;
    cout << "5. Exit" << endl;

    while (!exitMenu) {
        // Read a single character from the terminal
        char input;
        int result;
        read(STDIN_FILENO, &input, 1);


        switch (input) {
            case 'w':
                if (choice > 1) {
                    choice--;
                }
                break;
            case 's':
                if (choice < 5) {
                    choice++;
                }
                break;
            case '\n': // Enter key
                switch (choice) {
                    case 1:
                        result = run_game(difficulty);
                        if(result == 0) printWithSuspense("You Won!!!", delay1);
                        else if(result == 1) printWithSuspense("You Lost :(((", delay1);
                        else printWithSuspense("Draw", delay1);
                        cout << "Press Enter to continue..." << endl;
                        cin.ignore();
                        break;
                    case 2:
                        system("clear"); 
                        printWithSuspense(story, delay1);
                        cout << "Press Enter to continue..." << endl;
                        cin.ignore();
                        break;

                    case 3:
                        system("clear");
                        printWithSuspense(tutorial, delay2);
                        cout << "Press Enter to continue..." << endl;
                        cin.ignore();
                        break;
                    case 4:
                        system("clear"); 
                        printTheDifficultyMenu(difficulty);
                        read(STDIN_FILENO, &input, 1);
                        while (input != '\n')
                        {
                            if(input == 'w' && difficulty > 1) difficulty--;
                            else if(input == 's' && difficulty < 5) difficulty++;
                            system("clear"); 
                            printTheDifficultyMenu(difficulty);
                            read(STDIN_FILENO, &input, 1);
                        }
                        break;
                    case 5:
                        // Exit the menu
                        std::cout << "Exiting the menu." << std::endl;
                        exitMenu = true;
                        break;
                }
                break;
        }
        
        //print menu continuosly
        system("clear");
        cout << CYAN << "███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗     ██████╗  █████╗ ███╗   ███╗███████╗" << endl;
        cout << "██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝" << endl;
        cout << "███████╗██╔██╗ ██║███████║█████╔╝ █████╗      ██║  ███╗███████║██╔████╔██║█████╗  " << endl;
        cout << "╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝      ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  " << endl;
        cout << "███████║██║ ╚████║██║  ██║██║  ██╗███████╗    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗" << endl;
        cout << "╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝" <<  RESET << endl;
        std::cout << "=== Main Menu ===" << std::endl;
        for (int i = 1; i <= 5; i++) {
            if (i == choice) {
                std::cout << "> ";
            }
            std::cout << i << ". ";
            switch (i) {
                case 1:
                    std::cout << "Play";
                    break;
                case 2:
                    std::cout << "Story";
                    break;
                case 3:
                    std::cout << "Instructions";
                    break;
                case 4:
                    std::cout << "Difficulty";
                    break;
                case 5:
                    std::cout << "Exit";
                    break;
            }
            std::cout << std::endl;
        }
    }

    reset_terminal();

    return 0;
}
