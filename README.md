# Shoot and Merge Game

## Overview

This project is a console-based game where the player shoots numbers (powers of two) into a board and merges them based on certain rules. The game continues until the board is full, and the player's score is the total number of shots taken to fill the board.

## Features

- **Random Power of Two Generation**: Generates random powers of two based on the current maximum value.
- **Shooting Mechanism**: Allows the player to choose a column to shoot the number into.
- **Merging Mechanism**: Merges numbers in the column if they are the same.
- **Board Display**: Displays the current state of the board after each shot.
- **Replay Option**: Asks the player if they want to play again after the game ends.

## Getting Started

### Prerequisites

- A C compiler (e.g., `gcc`)

### Compilation

To compile the program, run:

```sh
gcc -o shoot_and_merge main.c
```

### Running the Program

To run the program, use the following command:

```sh
./shoot_and_merge
```

## Code Structure

### Main Function

The `main` function contains the main game loop, where the board is initialized, and the player is prompted to shoot numbers into the columns until the board is full. After the game ends, the player is asked if they want to play again.

### Helper Functions

1. **`randomPowerTwo`**: Generates a random power of two less than or equal to the given maximum value.
2. **`shootMerge`**: Shoots a number into the specified column, merges numbers if possible, and returns the new maximum value on the board.
3. **`fullorNot`**: Checks if the board is full.
4. **`displayBoard`**: Displays the current state of the board.
5. **`flushboard`**: Initializes the board to all zeros.

### Data Structures

- **Board**: A 5x4 grid that represents the game board.

## Detailed Description

### Main Function

- **Game Initialization**: Sets up the initial game state, including the board and initial random value.
- **Game Loop**: Continues until the board is full:
  - Prompts the player to choose a column to shoot the number into.
  - Validates the player's choice.
  - Shoots the number into the chosen column and merges numbers if possible.
  - Generates a new random power of two for the next shot.
  - Displays the current state of the board.
  - Increments the shot count.
- **Game Over**: When the board is full, displays the total number of shots taken and asks the player if they want to play again.

### Helper Functions

Each helper function performs a specific task to support the main game loop:

- **`randomPowerTwo`**: Uses the maximum value to generate a random power of two.
- **`shootMerge`**: Handles the logic for shooting a number into a column and merging numbers.
- **`fullorNot`**: Checks if the board is full by examining each cell.
- **`displayBoard`**: Prints the board to the console.
- **`flushboard`**: Resets the board to all zeros.

### Data Structures

- **Board**: A 2D array representing the 5x4 game board.

## Example Output

An example output of the program might look like this:

```plaintext
Lets get started!
        C1      C2      C3      C4

You have 2, which column would you like to shoot [1-4]? 2

        C1      C2      C3      C4
        2

1 shot so far!

You have 4, which column would you like to shoot [1-4]? 2

        C1      C2      C3      C4
        2       4

2 shots so far!
...

The board is full now with 20 shots!
Game over!
Would you like to play again (Y/N)? Y
```

## Conclusion

This project demonstrates a simple shooting and merging game using C programming. It covers random number generation, input validation, array manipulation, and console-based UI. The game can be easily modified to change the board size or rules for merging numbers.
