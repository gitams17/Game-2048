#include <bits/stdc++.h> // Include necessary headers

using namespace std;

struct Game2048 // Define a structure for the 2048 game
{
    int board[4][4]; // 2D array to represent the game board

    // Function to swipe tiles to the right in a row
    void swipe_right(int arr[])
    {
        int last_placed = 4; // Index to track the last placed tile
        int can_merge = 0;   // Flag to track if adjacent tiles can merge

        // Loop through the row from right to left
        for (int i = 3; i >= 0; i--)
        {
            if (arr[i] != 0) // If tile is not empty
            {
                if (can_merge) // If merging is possible
                {
                    if (arr[i] == arr[last_placed]) // If adjacent tiles are equal
                    {
                        arr[last_placed] *= 2; // Merge tiles
                        if (i != last_placed)
                            arr[i] = 0; // Clear the merged tile's position
                        can_merge = 0;  // Reset merge flag
                    }
                    else // If tiles are not equal
                    {
                        arr[last_placed - 1] = arr[i]; // Move tile to next empty position
                        last_placed--;                 // Update last placed index
                        if (i != last_placed)          // If tile was moved
                            arr[i] = 0;                // Clear original position
                        can_merge = 1;                 // Set merge flag
                    }
                }
                else // If no merging has been done yet
                {
                    arr[last_placed - 1] = arr[i]; // Move tile to next empty position
                    last_placed--;                 // Update last placed index
                    if (i != last_placed)
                        arr[i] = 0; // Clear original position
                    can_merge = 1;  // Set merge flag
                }
            }
        }
    }

    // Function to check if the game has ended
    bool has_game_ended()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == 0) // If any tile is empty
                {
                    return false; // Game is not ended
                }
            }
        }
        return true; // All tiles are filled, game ended
    }

    // Function to randomly populate the board with a 2 or 4
    void random_populate()
    {
        while (1)
        {
            int i = rand() % 4; // Generate random row index
            int j = rand() % 4; // Generate random column index

            if (board[i][j] == 0) // If the cell is empty
            {
                int choice = rand() % 2; // Randomly choose between 2 and 4
                if (choice == 0)
                    board[i][j] = 2; // Place 2
                else
                    board[i][j] = 4; // Place 4
                return;
            }
        }
    }

    // Function to initialize the game board
    void init()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                board[i][j] = 0; // Initialize all cells to 0
            }
        }
        random_populate(); // Populate board with initial tiles
        random_populate();
    }

    // Function to handle upward movement
    bool up()
    {
        for (int col = 0; col < 4; col++)
        {
            int arr[4];
            for (int row = 0; row < 4; row++)
            {
                arr[3 - row] = board[row][col]; // Extract column into array
            }
            swipe_right(arr); // Swipe the extracted column
            for (int row = 0; row < 4; row++)
            {
                board[row][col] = arr[3 - row]; // Place back the column into board
            }
        }
        return move_end(); // Check if the move has ended
    }

    // Function to handle downward movement
    bool down()
    {
        for (int col = 0; col < 4; col++)
        {
            int arr[4];
            for (int row = 0; row < 4; row++)
            {
                arr[row] = board[row][col]; // Extract column into array
            }
            swipe_right(arr); // Swipe the extracted column
            for (int row = 0; row < 4; row++)
            {
                board[row][col] = arr[row]; // Place back the column into board
            }
        }
        return move_end(); // Check if the move has ended
    }

    // Function to handle leftward movement
    bool left()
    {
        for (int row = 0; row < 4; row++)
        {
            int arr[4];
            for (int col = 0; col < 4; col++)
            {
                arr[3 - col] = board[row][col]; // Extract row into array
            }
            swipe_right(arr); // Swipe the extracted row
            for (int col = 0; col < 4; col++)
            {
                board[row][col] = arr[3 - col]; // Place back the row into board
            }
        }
        return move_end(); // Check if the move has ended
    }

    // Function to handle rightward movement
    bool right()
    {
        for (int row = 0; row < 4; row++)
        {
            int arr[4];
            for (int col = 0; col < 4; col++)
            {
                arr[col] = board[row][col]; // Extract row into array
            }
            swipe_right(arr); // Swipe the extracted row
            for (int col = 0; col < 4; col++)
            {
                board[row][col] = arr[col]; // Place back the row into board
            }
        }
        return move_end(); // Check if the move has ended
    }

    // Function to check if the move has ended
    bool move_end()
    {
        if (has_game_ended())
        {                // If game has ended
            return true; // Return true
        }
        else
        {
            random_populate(); // Otherwise, populate a random cell
            return false;      // Return false
        }
    }

    // Function to print the game board
    void print_board()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j])
                {
                    cout << board[i][j] << '\t'; // Print non-empty cell
                }
                else
                {
                    cout << " \t"; // Print empty cell
                }
            }
            cout << '\n'; // Move to the next row
        }
    }
};

// Main function
int main()
{
    srand(time(0));  // Seed the random number generator
    Game2048 mygame; // Create an instance of the Game2048 class
    mygame.init();   // Initialize the game board

    // Main game loop
    while (1)
    {
        mygame.print_board();              // Print the game board
        cout << "What move? (L, R, U, D)"; // Prompt for user input

        char ch;
        cin >> ch; // Read user input
        int ended;
        if (ch == 'U')
        {
            ended = mygame.up(); // Handle upward movement
        }
        else if (ch == 'D')
        {
            ended = mygame.down(); // Handle downward movement
        }
        else if (ch == 'R')
        {
            ended = mygame.right(); // Handle rightward movement
        }
        else if (ch == 'L')
        {
            ended = mygame.left(); // Handle leftward movement
        }
        else
        {
            cout << "INVALID MOVE\n"; // Print message for invalid move
        }
        if (ended)
        {                           // If the game has ended
            mygame.print_board();   // Print the final game board
            cout << "Game Ended\n"; // Print game ended message
            return 0;               // Exit the program
        }
    }

    return 0; // Return from main function
}
