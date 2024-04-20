# ENGG1340-Group-14-Project: Snake Game
Demo video:

## Team members 🧑‍💻👩‍💻
Das Josh Dunmore
Maharramov Ismayil
Medetova Aidana (3036191556)
Villamor Lester Aaron Antonio

## Description 🤖
**The Snake Game** is set in a post-apocalyptic world, evolving the classic snake gameplay into a narrative-driven, competitive experience. 
In this game, you control a snake, competing against an AI to gather scarce resources amidst a backdrop of nuclear winter and desolation.

**Your mission:** outsmart the AI opponent by consuming more food within a set time limit, demonstrating your worthiness as the next snake warrior to save humanity.

## How to play? 🧐
In the main menu, you have the following options:
- _Start Game:_ Jump right into the action.
- _Read Backstory:_ Immerse yourself in the lore of the world you're about to enter.
- _Choose Difficulty:_ Select the right level to match your skills, from beginner to expert.

**Controls**
- _WASD Keys:_ Use these keys to change your snake's moving direction, navigating the game area to collect food and avoid collisions.

**_Compilation and Execution Instructions_**
To play the game follow these simple steps
1. Compile the game by typing
`make main`
2. To start the game, enter:
`./main`
That's all!

## Features Implemented 🚀
**Random Generation of Game Elements**
- Food Placement: Utilizes the random function in C++ to decide the positions of food items on the game board, ensuring each game offers a unique challenge.

**Data Structures for Game Status**
- Game State Management:* We utilize a class named `GameState` in `Game.h` to encapsulate all relevant game information, such as the positions of all items on the board, the score, and the game time. This organization aids in maintaining clean state management and easy debugging.

**Memory Management**
- Game Entities: Using pointers and linked lists to manage dynamic elements of the game such as the snake's segments and food items, which are created and destroyed as the game progresses.

**Artificial Intelligence**
- AI Opponent: The game features an AI snake that competes against the player. The AI's movement decisions are governed by a set of algorithms that mimic strategic thinking, aiming to collect food efficiently while avoiding the player snake and the game boundaries.

**Programe codes in multiple files**
  - main.cpp: Sets up the game environment and handles user inputs.
  - Game.cpp and Game.h: Contain the core game mechanics and manage the game loop, including rendering and updates.
  - Player.cpp and Player.h: Define player-specific data and functionalities, such as score tracking and snake management.
  - Bot.cpp and Bot.h: Govern the AI snake's behavior, providing a challenging adversary for the player.

## Non-standard libraries 📖
**ncurses Library Integration:** Utilizes the `ncurses` library to create a responsive and visually appealing terminal-based user interface, enabling intuitive game control and display without the need for a graphical environment.

