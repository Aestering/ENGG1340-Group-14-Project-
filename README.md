# ENGG1340-Group-14-Project: Snake Game
Demo video:

### Team members 


### Description
**The Snake Game** is set in a post-apocalyptic world, evolving the classic snake gameplay into a narrative-driven, competitive experience. 
In this game, you control a snake, competing against an AI to gather scarce resources amidst a backdrop of nuclear winter and desolation.

**Your mission:** outsmart the AI opponent by consuming more food within a set time limit, demonstrating your worthiness as the next snake warrior to save humanity.

### How to play? 
In the main menu, you have the following options:
- _Start Game:_ Jump right into the action.
- _Read Backstory:_ Immerse yourself in the lore of the world you're about to enter.
- _Choose Difficulty:_ Select the right level to match your skills, from beginner to expert.

_Controls_
- _WASD Keys:_ Use these keys to change your snake's moving direction, navigating the game area to collect food and avoid collisions.

**_Compilation and Execution Instructions_**
To play the game follow these simple steps
1. Compile the game by typing
`make main`
2. To start the game, enter:
`./main`
That's all!

### Features Implemented 🚀
_Random Generation of Game Elements_
Food Placement: Utilizes the random function in C++ to decide the positions of food items on the game board, ensuring each game offers a unique challenge.

_Data Structures for Game Status_
Snake Growth and Movement: The snake's body is managed using a dynamic data structure, allowing efficient handling of changes in size and movement.
Score Tracking: An integer tracks the score based on the amount of food consumed.
Game Timer: Manages the countdown during each game session to enforce the time limit.

_Memory Management_
Game Entities: Using pointers and linked lists to manage dynamic elements of the game such as the snake's segments and food items, which are created and destroyed as the game progresses.

**Programe codes in multiple files**
  - main.cpp: Sets up the game environment and handles user inputs.
  - Game.cpp and Game.h: Contain the core game mechanics and manage the game loop, including rendering and updates.
  - Player.cpp and Player.h: Define player-specific data and functionalities, such as score tracking and snake management.
  - Bot.cpp and Bot.h: Govern the AI snake's behavior, providing a challenging adversary for the player.




### Non-standard libraries

