#include <iostream>
#include <vector>
using namespace std;

// Function to print the solution (chessboard)
void printSolution(const vector<vector<int>> &board)
{
    for (const auto &row : board)
    {
        for (int cell : row)
        {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Helper function to check if it's safe to place a queen at board[row][col]
bool isSafe(const vector<vector<int>> &board, int row, int col)
{
    int n = board.size();

    // Check the same column above
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    // Check the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(vector<vector<int>> &board, int row)
{
    int n = board.size();

    // Base case: All queens are placed
    if (row == n)
    {
        printSolution(board);
        return true; // Return true to print all possible solutions
    }

    bool foundSolution = false;

    // Try placing a queen in all columns of the current row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            // Place the queen
            board[row][col] = 1;

            // Recur to place queens in the next rows
            foundSolution |= solveNQueens(board, row + 1);

            // Backtrack: Remove the queen (try next column)
            board[row][col] = 0;
        }
    }

    return foundSolution;
}

int main()
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    // Initialize an empty chessboard
    vector<vector<int>> board(n, vector<int>(n, 0));

    // Solve the N-Queens problem
    if (!solveNQueens(board, 0))
    {
        cout << "No solution exists for " << n << " queens." << endl;
    }

    return 0;
}
