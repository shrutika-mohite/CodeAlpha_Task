#include <iostream>
#define N 4

// Function to print the 4x4 Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0)
                std::cout << "_ ";
            else
                std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if the number can be placed in the row, column, and 2x2 sub-grid
bool isValid(int grid[N][N], int row, int col, int num) {
    // Check the row and column for duplicates
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }

    // Check the 2x2 sub-grid
    int startRow = row - row % 2, startCol = col - col % 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}

// Function to check if the puzzle is completely solved
bool isPuzzleSolved(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0)
                return false;
        }
    }
    return true;
}

// Main game loop for interactive 4x4 Sudoku
void playSudoku(int grid[N][N]) {
    int row, col, num;
    while (!isPuzzleSolved(grid)) {
        printGrid(grid);

        // Get the user input for row, column, and number
        std::cout << "\nEnter the row (1-4), column (1-4), and number (1-4) separated by spaces: ";
        std::cin >> row >> col >> num;

        // Convert 1-based index to 0-based
        row--;
        col--;

        // Check if the move is valid
        if (grid[row][col] == 0 && isValid(grid, row, col, num)) {
            grid[row][col] = num; // Place the number
            std::cout << "Number placed successfully!\n";
        } else {
            std::cout << "Invalid move. Try again.\n";
        }

        std::cout << std::endl;
    }

    std::cout << "Congratulations! You have solved the 4x4 Sudoku puzzle!\n";
}

int main() {
    // Initial 4x4 Sudoku grid (0 represents empty cells)
    int grid[N][N] = {
        {1, 0, 0, 0},
        {0, 0, 3, 4},
        {3, 4, 0, 0},
        {0, 0, 0, 2}
    };

    // Start the interactive game
    playSudoku(grid);

    return 0;
}

