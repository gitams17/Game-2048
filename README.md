# 2048 Game Implementation in C++

This is a simple implementation of the popular game 2048 in C++. The game is played on a 4x4 grid where tiles slide when the player moves them in one of the four directions (up, down, left, right). When two tiles with the same number touch, they merge into one tile with the sum of their numbers. The goal of the game is to create a tile with the number 2048.

## How to Run the Game

1. Make sure you have a C++ compiler installed on your system.
2. Clone this repository to your local machine.
3. Navigate to the directory where you cloned the repository.
4. Compile the code using the C++ compiler. For example, if you're using g++, you can compile the code by running `g++ -o 2048_game 2048_game.cpp`.
5. Run the compiled executable file. For example, if you named the compiled file `2048_game`, you can run it by executing `./2048_game` in the terminal.

## How to Play

1. Once you run the game, you will see the initial game board printed in the console.
2. You will be prompted to enter a move: `What move? (L, R, U, D)`.
3. Enter one of the following characters to make a move:
   - `L` to move left.
   - `R` to move right.
   - `U` to move up.
   - `D` to move down.
4. After making a move, the game board will be updated, and a new tile will be randomly added to the board.
5. Continue making moves until you reach the target number 2048 or until there are no more valid moves left.

## Note

- This implementation uses the standard C++ library and does not require any additional dependencies.
- The game may end if the board is filled with tiles and no more valid moves can be made.
