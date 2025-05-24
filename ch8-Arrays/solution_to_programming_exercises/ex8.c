#include <stdio.h>      // For standard input/output functions (e.g., printf)
#include <stdlib.h>     // For abs() function to compute absolute value
#include <stdbool.h>    // For using bool, true, and false

#define N 8             // Define the size of the chessboard (8x8) and number of queens

int board[N];           // This array stores the column position of a queen in each row
                        // Example: board[0] = 4 means queen in row 0 is placed in column 4

int solution_count = 0; // This keeps track of how many valid solutions are found

// Function to check if placing a queen at (row, col) is safe
bool is_safe(int row, int col) {
    for (int i = 0; i < row; i++) {  // Check all previous rows
        // Check if there's a queen in the same column
        // or on the same diagonal as the current position
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;           // Not safe to place a queen here
        }
    }
    return true;                    // No conflicts, it's safe to place a queen
}

// Function to print the current board configuration (a valid solution)
void print_board() {
    printf("Solution #%d:\n", ++solution_count); // Print the solution number

    for (int i = 0; i < N; i++) {   // Loop through all rows
        for (int j = 0; j < N; j++) { // Loop through all columns
            if (board[i] == j)      // If the queen is in this column of the current row
                printf(" Q ");      // Print the queen
            else
                printf(" . ");      // Otherwise print a dot (empty square)
        }
        printf("\n");               // Move to next line after each row
    }
    printf("\n");                   // Add a blank line after each board
}

// Recursive function to solve the Eight Queens Problem
void solve(int row) {
    // Base case: If all rows are filled, we found a complete solution
    if (row == N) {
        print_board();              // Print the current solution
        return;                     // Go back to try other possibilities
    }

    // Try placing a queen in every column of the current row
    for (int col = 0; col < N; col++) {
        if (is_safe(row, col)) {    // If it's safe to place a queen at (row, col)
            board[row] = col;       // Place the queen in this column
            solve(row + 1);         // Recur to place queen in the next row
            // No need to remove the queen (backtrack), as we overwrite board[row]
        }
    }
}

// Entry point of the program
int main() {
    solve(0);                       // Start placing queens from the first row (row 0)
    printf("Total number of solutions: %d\n", solution_count); // Print final count
    return 0;                       // End the program
}

